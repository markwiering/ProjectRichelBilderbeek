#ifdef _WIN32
//See http://www.richelbilderbeek.nl/CppCompileErrorSwprintfHasNotBeenDeclared.htm
#undef __STRICT_ANSI__
#endif

//#include own header file as first substantive line of code, from:
// * John Lakos. Large-Scale C++ Software Design. 1996. ISBN: 0-201-63362-0. Section 3.2, page 110
#include "qtkalmanfilterexperimentmodel.h"

#include <cassert>
#include <boost/foreach.hpp>
#include <boost/lexical_cast.hpp>
#include <boost/numeric/conversion/cast.hpp>
#include <boost/regex.hpp>
#include <boost/algorithm/string/trim.hpp>

#include <string>
#include <vector>
#include <boost/algorithm/string/split.hpp>
#include <QMessageBox>

#include "fixedlagsmootherkalmanfilterparameters.h"
#include "kalmanfilterexperimentparameter.h"
#include "kalmanfilterfactory.h"
#include "laggedwhitenoisesystemparameters.h"
#include "kalmanfiltertypes.h"
#include "matrix.h"
#include "qtkalmanfilterermodel.h"
#include "standardkalmanfilterparameters.h"
#include "whitenoisesystemtype.h"
#include "standardwhitenoisesystemfactory.h"
#include "standardwhitenoisesystemparameters.h"
#include "trace.h"
#include "whitenoisesystemfactory.h"
#include "whitenoisesystemtypes.h"

QtKalmanFilterExperimentModel::QtKalmanFilterExperimentModel()
 : m_kalman_filter_type(KalmanFilterType::standard),
   m_lag_estimated(0),
   m_lag_real(0),
   m_models(CreateMap()),
   m_number_of_timesteps(0),
   m_white_noise_system_type(WhiteNoiseSystemType::standard)
{
  #ifndef NDEBUG
  Test();
  //Check for sizes
  const int n_rows = Find(KalmanFilterExperimentParameterType::state_names)->rowCount();
  const int n_cols = n_rows == 0 ? 0 : 1;
  assert(Find(KalmanFilterExperimentParameterType::control)->columnCount() == n_rows);
  assert(Find(KalmanFilterExperimentParameterType::control)->rowCount() == n_rows);
  assert(Find(KalmanFilterExperimentParameterType::estimated_measurement_noise)->columnCount() == n_rows);
  assert(Find(KalmanFilterExperimentParameterType::estimated_measurement_noise)->rowCount() == n_rows);
  assert(Find(KalmanFilterExperimentParameterType::estimated_optimal_kalman_gain)->columnCount() == n_rows);
  assert(Find(KalmanFilterExperimentParameterType::estimated_optimal_kalman_gain)->rowCount() == n_rows);
  assert(Find(KalmanFilterExperimentParameterType::estimated_process_noise_covariance)->columnCount() == n_rows);
  assert(Find(KalmanFilterExperimentParameterType::estimated_process_noise_covariance)->rowCount() == n_rows);
  assert(Find(KalmanFilterExperimentParameterType::initial_covariance_estimate)->columnCount() == n_rows);
  assert(Find(KalmanFilterExperimentParameterType::initial_covariance_estimate)->rowCount() == n_rows);
  assert(Find(KalmanFilterExperimentParameterType::initial_state_estimate)->columnCount() == n_cols);
  assert(Find(KalmanFilterExperimentParameterType::initial_state_estimate)->rowCount() == n_rows);
  assert(Find(KalmanFilterExperimentParameterType::initial_state_real)->columnCount() == n_cols);
  assert(Find(KalmanFilterExperimentParameterType::initial_state_real)->rowCount() == n_rows);
  assert(Find(KalmanFilterExperimentParameterType::input)->columnCount() == n_cols);
  assert(Find(KalmanFilterExperimentParameterType::input)->rowCount() == n_rows);
  assert(Find(KalmanFilterExperimentParameterType::observation)->columnCount() == n_rows);
  assert(Find(KalmanFilterExperimentParameterType::observation)->rowCount() == n_rows);
  assert(Find(KalmanFilterExperimentParameterType::real_measurement_noise)->columnCount() == n_cols);
  assert(Find(KalmanFilterExperimentParameterType::real_measurement_noise)->rowCount() == n_rows);
  assert(Find(KalmanFilterExperimentParameterType::real_process_noise)->columnCount() == n_cols);
  assert(Find(KalmanFilterExperimentParameterType::real_process_noise)->rowCount() == n_rows);
  assert(Find(KalmanFilterExperimentParameterType::state_names)->columnCount() == n_cols);
  assert(Find(KalmanFilterExperimentParameterType::state_names)->rowCount() == n_rows);
  assert(Find(KalmanFilterExperimentParameterType::state_transition)->columnCount() == n_rows);
  assert(Find(KalmanFilterExperimentParameterType::state_transition)->rowCount() == n_rows);
  assert(CreateKalmanFilter() && "Can create an empty Kalman filter");
  assert(CreateWhiteNoiseSystem() && "Can create an empty white noise system");
  assert(CreateExperiment() && "Can create an empty experiment");
  #endif


  //Let a state name change result in all models changing their headers
  {
    QAbstractTableModel * const m = Find(KalmanFilterExperimentParameterType::state_names);
    assert(m);
    QObject::connect(m,SIGNAL(dataChanged(QModelIndex,QModelIndex)),this,SLOT(OnStateNamesChanged(QModelIndex,QModelIndex)));
  }
}

const std::map<KalmanFilterExperimentParameterType,QAbstractTableModel *> QtKalmanFilterExperimentModel::CreateMap()
{
  std::map<KalmanFilterExperimentParameterType,QAbstractTableModel *> m;

  const std::vector<KalmanFilterExperimentParameterType> v = KalmanFilterExperimentParameter::GetAll();

  const auto j = v.end();
  for (auto i = v.begin(); i!=j; ++i)
  {
    KalmanFilterExperimentParameterType type = *i;
    QAbstractTableModel * const model = CreateModel(type);
    assert(model);
    m.insert(std::make_pair(type,model));
  }
  assert(static_cast<int>(KalmanFilterExperimentParameterType::n_parameters) == boost::numeric_cast<int>(m.size()));
  return m;
}


void QtKalmanFilterExperimentModel::CalculateOptimalEstimatedKalmanGain()
{
  //Read
  const auto initial_covariance_estimate =
    dynamic_cast<const InitialCovarianceEstimateModel*>(
      this->Find(KalmanFilterExperimentParameterType::initial_covariance_estimate)
    )->GetRawData();

  const auto estimated_measurement_noise =
    dynamic_cast<const EstimatedMeasurementNoiseModel*>(
      this->Find(KalmanFilterExperimentParameterType::estimated_measurement_noise)
    )->GetRawData();

  const auto observation =
    dynamic_cast<const ObservationModel*>(
      this->Find(KalmanFilterExperimentParameterType::observation)
    )->GetRawData();

  const auto state_transition =
    dynamic_cast<const StateTransitionModel*>(
      this->Find(KalmanFilterExperimentParameterType::state_transition)
    )->GetRawData();

  //Calculate
  const boost::numeric::ublas::matrix<double> m
    = SteadyStateKalmanFilterParameters::CalculateOptimalKalmanGain(
      initial_covariance_estimate,
      estimated_measurement_noise,
      observation,
      state_transition
    );

  //Write
  dynamic_cast<EstimatedOptimalKalmanGainModel*>(
    this->Find(KalmanFilterExperimentParameterType::estimated_optimal_kalman_gain)
  )->SetRawData(m);
}

const boost::shared_ptr<KalmanFilterExperiment> QtKalmanFilterExperimentModel::CreateExperiment() const
{

  boost::shared_ptr<KalmanFilterExperiment> experiment;


  const int n_timesteps_desired = this->m_number_of_timesteps;

  //assert(n_timesteps_desired > 0); //Can be zero

  const std::vector<std::string> input
    = dynamic_cast<const InputModel*>(
    this->Find(KalmanFilterExperimentParameterType::input)
  )->GetRawData();

  const boost::shared_ptr<KalmanFilter> kalman_filter = CreateKalmanFilter();
  if (!kalman_filter)
  {
    assert(!experiment);
    return experiment;
  }

  assert(kalman_filter->GetParameters());
  assert(input.size() == kalman_filter->GetParameters()->GetInitialStateEstimate().size());

  const std::vector<std::string> state_names
    = dynamic_cast<const StateNamesModel*>(
    this->Find(KalmanFilterExperimentParameterType::state_names)
  )->GetRawData();

  assert(input.size() == state_names.size());

  const boost::shared_ptr<WhiteNoiseSystem> white_noise_system = CreateWhiteNoiseSystem();

  if (!white_noise_system)
  {
    return experiment;
  }

  assert(state_names.size() == white_noise_system->PeekAtRealState().size());
  assert(Matrix::MatricesAreAboutEqual(
    kalman_filter->GetParameters()->GetControl(),
    white_noise_system->GetParameters()->GetControl())
    && "Parameters obtained from Kalman filter and white noise system must match");
  assert(Matrix::MatricesAreAboutEqual(
    kalman_filter->GetParameters()->GetStateTransition(),
    white_noise_system->GetParameters()->GetStateTransition())
    && "Parameters obtained from Kalman filter and white noise system must match");

  experiment.reset(
    new KalmanFilterExperiment(
      n_timesteps_desired,
      input,
      kalman_filter,
      state_names,
      white_noise_system)
    );

  assert(experiment);
  return experiment;
}


const boost::shared_ptr<KalmanFilterParameters> QtKalmanFilterExperimentModel::CreateFixedLagSmootherKalmanFilterParameters() const
{
  const boost::shared_ptr<StandardKalmanFilterParameters> standard_parameters
    = CreateStandardKalmanFilterParameters();
  const int estimated_lag = this->m_lag_estimated;

  const boost::shared_ptr<FixedLagSmootherKalmanFilterParameters> p(
    new FixedLagSmootherKalmanFilterParameters(
      standard_parameters,
      estimated_lag
    )
  );
  assert(p);
  return p;
}

const boost::shared_ptr<KalmanFilter> QtKalmanFilterExperimentModel::CreateKalmanFilter() const
{
  const boost::shared_ptr<const KalmanFilterParameters> parameters = CreateKalmanFilterParameters();
  assert(parameters);
  const boost::shared_ptr<KalmanFilter> kalman_filter = KalmanFilterFactory::Create(parameters);
  assert(kalman_filter);
  return kalman_filter;
}

const boost::shared_ptr<KalmanFilterParameters> QtKalmanFilterExperimentModel::CreateKalmanFilterParameters() const
{
  boost::shared_ptr<KalmanFilterParameters> parameters;
  switch (m_kalman_filter_type)
  {
    case KalmanFilterType::standard:
      parameters = CreateStandardKalmanFilterParameters();
      break;
    case KalmanFilterType::steady_state:
      parameters = CreateSteadyStateKalmanFilterParameters();
      break;
    case KalmanFilterType::fixed_lag_smoother:
      parameters = CreateFixedLagSmootherKalmanFilterParameters();
      break;
    case KalmanFilterType::n_types:
      assert(!"Unimplemented Kalman filter type");
      throw std::logic_error(__func__);
  }
  assert(parameters);
  assert(parameters->GetType() == m_kalman_filter_type);
  return parameters;
}

const boost::shared_ptr<StandardKalmanFilterParameters> QtKalmanFilterExperimentModel::CreateStandardKalmanFilterParameters() const
{
  const auto control =
    dynamic_cast<const ControlModel*>(
      this->Find(KalmanFilterExperimentParameterType::control)
    )->GetRawData();

  const auto estimated_measurement_noise =
    dynamic_cast<const EstimatedMeasurementNoiseModel*>(
      this->Find(KalmanFilterExperimentParameterType::estimated_measurement_noise)
    )->GetRawData();

  const auto estimated_process_noise_covariance =
    dynamic_cast<const EstimatedProcessNoiseCovarianceModel*>(
      this->Find(KalmanFilterExperimentParameterType::estimated_process_noise_covariance)
    )->GetRawData();

  const auto initial_covariance_estimate =
    dynamic_cast<const InitialCovarianceEstimateModel*>(
      this->Find(KalmanFilterExperimentParameterType::initial_covariance_estimate)
    )->GetRawData();

  const auto initial_state_estimate =
    dynamic_cast<const InitialStateEstimateModel*>(
      this->Find(KalmanFilterExperimentParameterType::initial_state_estimate)
    )->GetRawData();

  const auto observation =
    dynamic_cast<const ObservationModel*>(
      this->Find(KalmanFilterExperimentParameterType::observation)
    )->GetRawData();

  const auto state_transition =
    dynamic_cast<const StateTransitionModel*>(
      this->Find(KalmanFilterExperimentParameterType::state_transition)
    )->GetRawData();

  #ifndef NDEBUG
  const std::size_t sz = initial_state_estimate.size();
  //assert(sz >= 0); //Inevitable for std::size_t
  assert(sz == control.size1());
  assert(sz == control.size2());
  assert(sz == observation.size1());
  assert(sz == observation.size2());
  assert(sz == state_transition.size1());
  assert(sz == state_transition.size2());
  assert(sz == initial_state_estimate.size());
  #endif
  const boost::shared_ptr<StandardKalmanFilterParameters> p(
    new StandardKalmanFilterParameters(
      control,
      estimated_measurement_noise,
      estimated_process_noise_covariance,
      initial_covariance_estimate,
      initial_state_estimate,
      observation,
      state_transition
    )
  );
  assert(p);
  return p;
}

const boost::shared_ptr<KalmanFilterParameters> QtKalmanFilterExperimentModel::CreateSteadyStateKalmanFilterParameters() const
{
  const auto control =
    dynamic_cast<const ControlModel*>(
      this->Find(KalmanFilterExperimentParameterType::control)
    )->GetRawData();

  const auto estimated_optimal_kalman_gain =
    dynamic_cast<const EstimatedOptimalKalmanGainModel*>(
      this->Find(KalmanFilterExperimentParameterType::estimated_optimal_kalman_gain)
    )->GetRawData();

  const auto initial_state_estimate =
    dynamic_cast<const InitialStateEstimateModel*>(
      this->Find(KalmanFilterExperimentParameterType::initial_state_estimate)
    )->GetRawData();

  const auto observation =
    dynamic_cast<const ObservationModel*>(
      this->Find(KalmanFilterExperimentParameterType::observation)
    )->GetRawData();

  const auto state_transition =
    dynamic_cast<const StateTransitionModel*>(
      this->Find(KalmanFilterExperimentParameterType::state_transition)
    )->GetRawData();

  const boost::shared_ptr<SteadyStateKalmanFilterParameters> p(
    new SteadyStateKalmanFilterParameters(
      control,
      estimated_optimal_kalman_gain,
      initial_state_estimate,
      observation,
      state_transition
    )
  );
  assert(p);
  return p;
}

const boost::shared_ptr<WhiteNoiseSystemParameters> QtKalmanFilterExperimentModel::CreateLaggedWhiteNoiseSystemParameters() const
{
  const auto control =
    dynamic_cast<const ControlModel*>(
      this->Find(KalmanFilterExperimentParameterType::control)
    )->GetRawData();

  const auto initial_state_real =
    dynamic_cast<const InitialStateRealModel*>(
      this->Find(KalmanFilterExperimentParameterType::initial_state_real)
    )->GetRawData();

  const auto real_measurement_noise =
    dynamic_cast<const RealMeasurementNoiseModel*>(
      this->Find(KalmanFilterExperimentParameterType::real_measurement_noise)
    )->GetRawData();

  const auto real_process_noise =
    dynamic_cast<const RealProcessNoiseModel*>(
      this->Find(KalmanFilterExperimentParameterType::real_process_noise)
    )->GetRawData();

  const auto state_transition =
    dynamic_cast<const StateTransitionModel*>(
      this->Find(KalmanFilterExperimentParameterType::state_transition)
    )->GetRawData();

  const boost::shared_ptr<WhiteNoiseSystemParameters> p(
    new LaggedWhiteNoiseSystemParameters(
      control,
      initial_state_real,
      m_lag_real,
      real_measurement_noise,
      real_process_noise,
      state_transition
    )
  );
  assert(p);
  assert(p->GetType() == WhiteNoiseSystemType::lagged);
  return p;
}


QAbstractTableModel * QtKalmanFilterExperimentModel::CreateModel(const KalmanFilterExperimentParameterType type)
{
  switch (type)
  {
    case KalmanFilterExperimentParameterType::control:
      return new ControlModel;
    case KalmanFilterExperimentParameterType::estimated_measurement_noise:
      return new EstimatedMeasurementNoiseModel;
    case KalmanFilterExperimentParameterType::estimated_optimal_kalman_gain:
      return new EstimatedOptimalKalmanGainModel;
    case KalmanFilterExperimentParameterType::estimated_process_noise_covariance:
      return new EstimatedProcessNoiseCovarianceModel;
    case KalmanFilterExperimentParameterType::initial_covariance_estimate:
      return new InitialCovarianceEstimateModel;
    case KalmanFilterExperimentParameterType::initial_state_estimate:
      return new InitialStateEstimateModel;
    case KalmanFilterExperimentParameterType::initial_state_real:
      return new InitialStateRealModel;
    case KalmanFilterExperimentParameterType::real_measurement_noise:
      return new RealMeasurementNoiseModel;
    case KalmanFilterExperimentParameterType::real_process_noise:
      return new RealProcessNoiseModel;
    case KalmanFilterExperimentParameterType::input:
      return new InputModel("t");
    case KalmanFilterExperimentParameterType::observation:
      return new ObservationModel;
    case KalmanFilterExperimentParameterType::state_names:
      return new StateNamesModel;
    case KalmanFilterExperimentParameterType::state_transition:
      return new StateTransitionModel;
    case KalmanFilterExperimentParameterType::n_parameters:
      assert(!"Should not get here");
      throw std::logic_error("QtKalmanFiltererParameterDialog::ToModel");
  }
  assert(!"Should not get here");
  throw std::logic_error("QtKalmanFiltererParameterDialog::ToModel");
}

const boost::shared_ptr<StandardWhiteNoiseSystemParameters> QtKalmanFilterExperimentModel::CreateStandardWhiteNoiseSystemParameters() const
{
  const auto control =
    dynamic_cast<const ControlModel*>(
      this->Find(KalmanFilterExperimentParameterType::control)
    )->GetRawData();

  assert(this->Find(KalmanFilterExperimentParameterType::initial_state_real));
  assert(dynamic_cast<const InitialStateRealModel*>(
      this->Find(KalmanFilterExperimentParameterType::initial_state_real)));

  const auto initial_state_real =
    dynamic_cast<const InitialStateRealModel*>(
      this->Find(KalmanFilterExperimentParameterType::initial_state_real)
    )->GetRawData();

  const auto real_measurement_noise =
    dynamic_cast<const RealMeasurementNoiseModel*>(
      this->Find(KalmanFilterExperimentParameterType::real_measurement_noise)
    )->GetRawData();

  const auto real_process_noise =
    dynamic_cast<const RealProcessNoiseModel*>(
      this->Find(KalmanFilterExperimentParameterType::real_process_noise)
    )->GetRawData();

  const auto state_transition =
    dynamic_cast<const StateTransitionModel*>(
      this->Find(KalmanFilterExperimentParameterType::state_transition)
    )->GetRawData();

  const boost::shared_ptr<StandardWhiteNoiseSystemParameters> p(
    new StandardWhiteNoiseSystemParameters(
      control,
      initial_state_real,
      real_measurement_noise,
      real_process_noise,
      state_transition
    )
  );
  assert(p);
  assert(p->GetType() == WhiteNoiseSystemType::standard);
  return p;
}

const boost::shared_ptr<WhiteNoiseSystem> QtKalmanFilterExperimentModel::CreateWhiteNoiseSystem() const
{
  const boost::shared_ptr<WhiteNoiseSystemParameters> parameters
    = CreateWhiteNoiseSystemParameters();
  assert(parameters);
  assert(this->m_white_noise_system_type == parameters->GetType());
  const boost::shared_ptr<WhiteNoiseSystem> my_system
    = WhiteNoiseSystemFactory::Create(parameters);
  assert(my_system);
  assert(my_system->GetType() == parameters->GetType());
  return my_system;
}

const boost::shared_ptr<WhiteNoiseSystemParameters> QtKalmanFilterExperimentModel::CreateWhiteNoiseSystemParameters() const
{
  boost::shared_ptr<WhiteNoiseSystemParameters> parameters;
  switch (m_white_noise_system_type)
  {
    case WhiteNoiseSystemType::standard:
    {
      parameters = CreateStandardWhiteNoiseSystemParameters();
    }
    break;
    case WhiteNoiseSystemType::lagged:
    {
      parameters = CreateLaggedWhiteNoiseSystemParameters();
    }
    break;
    case WhiteNoiseSystemType::n_types:
      assert(!"Unimplemented white noise system type");
  }
  assert(parameters);
  return parameters;
}

QAbstractTableModel * QtKalmanFilterExperimentModel::Find(const KalmanFilterExperimentParameterType type)
{
  //Calls the const version of Find
  //To avoid duplication in const and non-const member functions
  // * Herb Sutter, Andrei Alexandrescu. C++ coding standards: 101 rules, guidelines,
  //   and best practices. 2005. ISBN: 0-32-111358-6. Chapter 94: 'Avoid casting away const', item 'Exceptions'
  return const_cast<QAbstractTableModel *>(const_cast<const QtKalmanFilterExperimentModel&>(*this).Find(type));
}

const QAbstractTableModel * QtKalmanFilterExperimentModel::Find(const KalmanFilterExperimentParameterType type) const
{
  assert(m_models.find(type) != m_models.end());
  const QAbstractTableModel * const model = (*m_models.find(type)).second;
  assert(model);
  return model;
}

void QtKalmanFilterExperimentModel::FromDokuWiki(const std::string& text)
{
  const std::vector<std::string> lines = SeperateString(text,'\n');
  assert(!lines.empty());
  const int n_lines = boost::numeric_cast<int>(lines.size());
  for (int line=0; line!=n_lines; ++line)
  {
    const std::string& line_str = lines[line];

    //Have to do manually as Boost.Regex its boost::regex_replace
    //does not link under GCC 4.4.0

    ReadKalmanFilterType(line_str);
    Read(line_str,"Lag estimated",m_lag_estimated);
    Read(line_str,"Lag real",m_lag_real);
    Read(line_str,"Number of timesteps",m_number_of_timesteps);
    ReadWhiteNoiseSystemType(line_str);

  }
  //Go through all m_models
  {
    typedef std::map<KalmanFilterExperimentParameterType,QAbstractTableModel *>::const_iterator Iterator;
    const Iterator j = m_models.end();
    for (Iterator i = m_models.begin(); i!=j; ++i)
    {
      const std::pair<KalmanFilterExperimentParameterType,QAbstractTableModel *> p = *i;
      KalmanFilterExperimentParameterType type = p.first;
      QAbstractTableModel * const model = p.second;
      assert(type != KalmanFilterExperimentParameterType::n_parameters);
      assert(model);
      const std::string name = KalmanFilterExperimentParameter::ToName(type);
      Read(lines,name,model);
    }
  }
}

void QtKalmanFilterExperimentModel::OnStateNamesChanged(const QModelIndex &/*topLeft*/, const QModelIndex &/*bottomRight*/)
{
  //Read
  const std::vector<std::string> state_names =
  dynamic_cast<StateNamesModel*>(
    this->Find(KalmanFilterExperimentParameterType::state_names)
  )->GetRawData();

  //Write to all headers
  const auto j = m_models.end();
  for (auto i = m_models.begin(); i!=j; ++i)
  {
    const std::pair<KalmanFilterExperimentParameterType,QAbstractTableModel *> p = *i;
    const KalmanFilterExperimentParameterType type = p.first;
    QAbstractTableModel * const abstract_model = p.second;

    if (QtStdVectorStringModel * const svs_model = dynamic_cast<QtStdVectorStringModel *>(abstract_model))
    {
      const std::string title = KalmanFilterExperimentParameter::ToSymbol(type);
      svs_model->SetHeaderData(title,state_names);
    }
    else if (QtStdVectorFunctionModel * const svf_model = dynamic_cast<QtStdVectorFunctionModel *>(abstract_model))
    {
      const std::string title = KalmanFilterExperimentParameter::ToSymbol(type);
      svf_model->SetHeaderData(title,state_names);
    }
    else if (QtUblasMatrixDoubleModel * const umd_model = dynamic_cast<QtUblasMatrixDoubleModel *>(abstract_model))
    {
      umd_model->SetHeaderData(state_names,state_names);
    }
    else
    {
      QtUblasVectorDoubleModel * const uvd_model = dynamic_cast<QtUblasVectorDoubleModel *>(abstract_model);
      assert(uvd_model);
      const std::string title = KalmanFilterExperimentParameter::ToSymbol(type);
      uvd_model->SetHeaderData(title,state_names);
    }
  }

}

void QtKalmanFilterExperimentModel::ReadKalmanFilterType(const std::string& s)
{
  if (s.find("Kalman filter type") != std::string::npos)
  {
    const std::vector<KalmanFilterType> v = KalmanFilterTypes::GetAllTypes();
    BOOST_FOREACH(const KalmanFilterType type, v)
    {
      if (s.find(KalmanFilterTypes::ToStr(type)) != std::string::npos)
      {
        this->m_kalman_filter_type = type;
      }
    }
  }
}

void QtKalmanFilterExperimentModel::Read(const std::vector<std::string>& text,const std::string& name, QAbstractTableModel * const model)
{
  assert(model);
  assert(!text.empty());
  const int sz = boost::numeric_cast<int>(text.size());

  //Find begin
  const std::string header = std::string("^ ") + name;
  int begin_tmp = -1;
  for (int i=0; i!=sz; ++i)
  {
    if (text[i].find(header) != std::string::npos) { begin_tmp = i; break; }
  }
  assert(begin_tmp != -1);
  assert(begin_tmp < boost::numeric_cast<int>(text.size()));

  const int begin = begin_tmp;

  //Calculate number of columns
  const int n_cols = std::count(text[begin].begin(),text[begin].end(),'^') - 2;
  if (n_cols == 0) return;
  assert(n_cols > 0);

  //Find end
  int end_tmp = -1;
  for (int i=begin; i!=sz; ++i)
  {
    if (boost::algorithm::trim_copy(text[i]).empty()) { end_tmp = i; break; }
  }
  assert(end_tmp != -1);
  assert(end_tmp < boost::numeric_cast<int>(text.size()));

  const int end = end_tmp;

  //Calculate number of rows
  const int n_rows = end - begin - 1; //-1 for header
  if (n_rows == 0) return;
  assert(n_rows > 0);

  //Resize model
  //Columns
  if (model->columnCount() < n_cols)
  {
    const int n_to_add = n_cols - model->columnCount();
    model->insertColumns(0,n_to_add);
    assert(model->columnCount() == n_cols);
  }
  else if (model->columnCount() > n_cols)
  {
    const int n_to_remove = model->columnCount() - n_cols;
    model->removeColumns(0,n_to_remove);
    assert(model->columnCount() == n_cols);
  }
  assert(model->columnCount() == n_cols);

  //Rows
  if (model->rowCount() < n_rows)
  {
    const int n_to_add = n_rows - model->rowCount();
    model->insertRows(0,n_to_add);
    assert(model->rowCount() == n_rows);
  }
  else if (model->rowCount() > n_rows)
  {
    const int n_to_remove = model->rowCount() - n_rows;
    model->removeRows(0,n_to_remove);
    assert(model->rowCount() == n_rows);
  }
  assert(model->rowCount() == n_rows);


  //Fill model with data
  for (int row = 0; row!=n_rows; ++row)
  {
    const int line = begin + 1 + row;
    assert(line < boost::numeric_cast<int>(text.size()));
    const std::vector<std::string> cols = SeperateString(text[line],'|');
    assert(boost::numeric_cast<int>(cols.size()) == n_cols + 2); // HEADER | value | value | space
    for (int col = 0; col!=n_cols; ++col)
    {
      const int col_index = col + 1; //Skip header
      assert(col_index < boost::lexical_cast<int>(cols.size()));
      assert(row < model->rowCount());
      assert(col < model->columnCount());
      const QModelIndex index = model->index(row,col);
      //Need to strip whitespace
      const std::string data_str = cols[col_index].c_str();
      const QString data = boost::algorithm::trim_copy(data_str).c_str();
      model->setData(index,data);
    }
  }
}

void QtKalmanFilterExperimentModel::Read(const std::string& line,const std::string& sub, int& value_to_change)
{
  if (line.find(sub) != std::string::npos)
  {
    if (line.substr(line.size() - 5,5) == std::string("</li>"))
    {
      Read(line.substr(0,line.size() - 5),sub,value_to_change);
      return;
    }
    for (int n_digits = 1; ; ++n_digits)
    {
      try
      {
        const int value
          = boost::lexical_cast<int>(
            line.substr(
                line.size() - n_digits,n_digits
              )
            );
         value_to_change = value;
      }
      catch (boost::bad_lexical_cast&)
      {
        return;
      }
    }
  }
}

void QtKalmanFilterExperimentModel::ReadWhiteNoiseSystemType(const std::string& s)
{
  if (s.find("White noise system type") != std::string::npos)
  {
    const std::vector<WhiteNoiseSystemType> v = WhiteNoiseSystemTypes::GetAllTypes();
    BOOST_FOREACH(const WhiteNoiseSystemType type, v)
    {
      if (s.find(WhiteNoiseSystemTypes::ToStr(type)) != std::string::npos)
      {
        this->m_white_noise_system_type = type;
      }
    }
  }
}


const std::vector<std::string> QtKalmanFilterExperimentModel::SeperateString(
  const std::string& input,
  const char seperator)
{
  std::vector<std::string> v;
  boost::algorithm::split(v,input,
    std::bind2nd(std::equal_to<char>(),seperator),
    boost::algorithm::token_compress_on);
  return v;
}

void QtKalmanFilterExperimentModel::SetExample(const boost::shared_ptr<const KalmanFilterExample>& example)
{

  assert(example);
  dynamic_cast<StateNamesModel*>(
    this->Find(KalmanFilterExperimentParameterType::state_names)
  )->SetRawData(example->GetStateNames());


  dynamic_cast<InputModel*>(
    this->Find(KalmanFilterExperimentParameterType::input)
  )->SetRawData(example->GetInputs());


  this->SetKalmanFilterType(example->GetKalmanFilterParameters()->GetType());


  assert(this->Find(KalmanFilterExperimentParameterType::control));
  assert(dynamic_cast<ControlModel*>(
    this->Find(KalmanFilterExperimentParameterType::control)
  ));

  dynamic_cast<ControlModel*>(
    this->Find(KalmanFilterExperimentParameterType::control)
  )->SetRawData(example->GetKalmanFilterParameters()->GetControl());


  dynamic_cast<EstimatedMeasurementNoiseModel*>(
    this->Find(KalmanFilterExperimentParameterType::estimated_measurement_noise)
  )->SetRawData(example->GetKalmanFilterParameters()->GetEstimatedMeasurementNoise());


  dynamic_cast<EstimatedProcessNoiseCovarianceModel*>(
    this->Find(KalmanFilterExperimentParameterType::estimated_process_noise_covariance)
  )->SetRawData(example->GetKalmanFilterParameters()->GetEstimatedProcessNoiseCovariance());


  dynamic_cast<InitialCovarianceEstimateModel*>(
    this->Find(KalmanFilterExperimentParameterType::initial_covariance_estimate)
  )->SetRawData(example->GetKalmanFilterParameters()->GetInitialCovarianceEstimate());


  dynamic_cast<InitialStateEstimateModel*>(
    this->Find(KalmanFilterExperimentParameterType::initial_state_estimate)
  )->SetRawData(example->GetKalmanFilterParameters()->GetInitialStateEstimate());


  dynamic_cast<ObservationModel*>(
    this->Find(KalmanFilterExperimentParameterType::observation)
  )->SetRawData(example->GetKalmanFilterParameters()->GetObservation());


  dynamic_cast<StateTransitionModel*>(
    this->Find(KalmanFilterExperimentParameterType::state_transition)
  )->SetRawData(example->GetKalmanFilterParameters()->GetStateTransition());

  this->SetWhiteNoiseSystemType(example->GetWhiteNoiseSystemParameters()->GetType());

  assert(
    Matrix::MatricesAreEqual(
      example->GetWhiteNoiseSystemParameters()->GetControl(),
      example->GetKalmanFilterParameters()->GetControl()
    )
    && "This is the purpose of using model/view: these must be the same");

  dynamic_cast<InitialStateRealModel*>(
    this->Find(KalmanFilterExperimentParameterType::initial_state_real)
  )->SetRawData(example->GetWhiteNoiseSystemParameters()->GetInitialState());

  dynamic_cast<RealMeasurementNoiseModel*>(
    this->Find(KalmanFilterExperimentParameterType::real_measurement_noise)
  )->SetRawData(example->GetWhiteNoiseSystemParameters()->GetMeasurementNoise());

  dynamic_cast<RealProcessNoiseModel*>(
    this->Find(KalmanFilterExperimentParameterType::real_process_noise)
  )->SetRawData(example->GetWhiteNoiseSystemParameters()->GetProcessNoise());



  assert(
    Matrix::MatricesAreEqual(
      example->GetWhiteNoiseSystemParameters()->GetStateTransition(),
      example->GetKalmanFilterParameters()->GetStateTransition()
    )
    && "This is the purpose of using model/view: these must be the same");


}

void QtKalmanFilterExperimentModel::SetKalmanFilterType(const KalmanFilterType type)
{
  m_kalman_filter_type = type;
}

void QtKalmanFilterExperimentModel::SetLagReal(const int lag)
{
  m_lag_real = lag;
}

void QtKalmanFilterExperimentModel::SetNumberOfTimesteps(const int n)
{
  m_number_of_timesteps = n;
}

void QtKalmanFilterExperimentModel::SetWhiteNoiseSystemType(const WhiteNoiseSystemType type)
{
  m_white_noise_system_type = type;
}

#ifndef NDEBUG
void QtKalmanFilterExperimentModel::Test()
{
  {
    static bool is_tested = false;
    if (is_tested) return;
    is_tested = true;
  }
  //Test some regexes
  {
    const std::string s = "ABC\nPre: GETME\nDEF";
    const boost::regex r("(.*)(\nPre: )(.*)(\n)(.*)");
    assert(boost::regex_search(s,r));
    const std::string t
      = boost::regex_replace(
      s,r,"$3",
      boost::match_default | boost::format_all);
     assert(t == std::string("GETME"));
  }
}
#endif

const std::string QtKalmanFilterExperimentModel::ToDokuWiki() const
{
  std::stringstream s;
  s << "  * Kalman filter type: " << KalmanFilterTypes::ToStr(m_kalman_filter_type) << "\n"
    << "  * Lag estimated: " << boost::lexical_cast<std::string>(m_lag_estimated) << "\n"
    << "  * Lag real: " << boost::lexical_cast<std::string>(m_lag_real) << "\n"
    << "  * Number of timesteps: " << boost::lexical_cast<std::string>(m_number_of_timesteps) << "\n"
    << "  * White noise system type: " << WhiteNoiseSystemTypes::ToStr(m_white_noise_system_type) << "\n"
    << " \n";
  //Go through all m_models
  {
    typedef std::map<KalmanFilterExperimentParameterType,QAbstractTableModel *>::const_iterator Iterator;
    const Iterator j = m_models.end();
    for (Iterator i = m_models.begin(); i!=j; ++i)
    {
      const std::pair<KalmanFilterExperimentParameterType,QAbstractTableModel *> p = *i;
      KalmanFilterExperimentParameterType type = p.first;
      const QAbstractTableModel * const model = p.second;
      assert(type != KalmanFilterExperimentParameterType::n_parameters);
      assert(model);
      const std::string name = KalmanFilterExperimentParameter::ToName(type);
      const int n_cols = model->columnCount();
      const int n_rows = model->rowCount();

      assert(n_cols >= 0);
      assert(n_rows >= 0);
      assert(std::string(0,'^') == std::string(""));
      s << std::string("^ ") << name << " " << std::string(n_cols,'^') << "^ \n";
      for (int row = 0; row!=n_rows; ++row)
      {
        s  << std::string("^ ") << model->headerData(row,Qt::Vertical).toString().toStdString() << std::string(" | ");
        for (int col = 0; col!=n_cols; ++col)
        {
          const QModelIndex index = model->index(row,col);
          const QString q = model->data(index).toString();
          s << q.toStdString() << std::string(" | ");
        }
        s << std::string("\n");
      }
      s << std::string(" \n"); //Empty line after every table, space is really needed
    }
  }
  const std::string text = s.str();
  return text;
}


const std::string QtKalmanFilterExperimentModel::ToHtml() const
{
  std::string s =

  "<!DOCTYPE html PUBLIC \"-//W3C//DTD XHTML 1.0 Strict//EN\""
  "  \"http://www.w3.org/TR/xhtml1/DTD/xhtml1-strict.dtd\">"
  "<html xmlns=\"http://www.w3.org/1999/xhtml\" lang=\"en\" xml:lang=\"en\">"
  "<head>"
  "<meta http-equiv=\"Content-Type\" content=\"text/html;charset=utf-8\"/>"
  "<title>KalmanFilterer parameters</title>"
  "<meta name=\"description\" content=\"KalmanFilterer parameters\"/>"
  "<meta name=\"keywords\" content=\"KalmanFilterer parameters\"/>"
  "<link rel=\"stylesheet\" href=\"Richelbilderbeek.css\" type=\"text/css\"/>"
  "</head>"
  "<!-- End of head, start of body -->"
  "<body>";


  s+="<h1>KalmanFilterer parameters</h1>";
  s+="<p>&nbsp</p>";
  s+="<ul>";
  s+="  <li>Kalman filter type: " + KalmanFilterTypes::ToStr(m_kalman_filter_type) + "</li>";
  s+="  <li>Lag estimated: " + boost::lexical_cast<std::string>(m_lag_estimated) + "</li>";
  s+="  <li>Lag real: " + boost::lexical_cast<std::string>(m_lag_real) + "</li>";
  s+="  <li>Number of timesteps: " + boost::lexical_cast<std::string>(m_number_of_timesteps) + "</li>";
  s+="  <li>White noise system type: " + WhiteNoiseSystemTypes::ToStr(m_white_noise_system_type) + "</li>";
  s+="</ul>";
  s+="<p>&nbsp</p>";

  //Go through all m_models
  {
    typedef std::map<KalmanFilterExperimentParameterType,QAbstractTableModel *>::const_iterator Iterator;
    const Iterator j = m_models.end();
    for (Iterator i = m_models.begin(); i!=j; ++i)
    {
      const std::pair<KalmanFilterExperimentParameterType,QAbstractTableModel *> p = *i;
      KalmanFilterExperimentParameterType type = p.first;
      const QAbstractTableModel * const model = p.second;
      assert(type != KalmanFilterExperimentParameterType::n_parameters);
      assert(model);
      const std::string name = KalmanFilterExperimentParameter::ToName(type);
      s+="<h2>" + name + "</h2>";
      s+="<table summary=\"" + name + "\" border=\"1\">";
      const int n_cols = model->columnCount();
      const int n_rows = model->rowCount();
      for (int row = 0; row!=n_rows; ++row)
      {
        s +="<tr>";
        for (int col = 0; col!=n_cols; ++col)
        {
          s +="<td>";
          const QModelIndex index = model->index(row,col);
          const QString q = model->data(index).toString();
          s += q.toStdString();
          s +="</td>";
        }
        s +="</tr>";
      }
      s += "</table>";
    }
  }
  s+="</body>";
  s+="</html>";
  return s;
}
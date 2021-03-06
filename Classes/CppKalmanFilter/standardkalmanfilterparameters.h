#ifndef STANDARDKALMANFILTERPARAMETERS_H
#define STANDARDKALMANFILTERPARAMETERS_H

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wunused-local-typedefs"
#include <boost/checked_delete.hpp>
#include <boost/numeric/ublas/matrix.hpp>

#include "kalmanfilterparameters.h"

#pragma GCC diagnostic pop

///Parameters for the standard Kalman filter
struct StandardKalmanFilterParameters : public KalmanFilterParameters
{
  StandardKalmanFilterParameters(
    const boost::numeric::ublas::matrix<double>& control,
    const boost::numeric::ublas::matrix<double>& estimated_measurement_noise,
    const boost::numeric::ublas::matrix<double>& estimated_process_noise_covariance,
    const boost::numeric::ublas::matrix<double>& initial_covariance_estimate,
    const boost::numeric::ublas::vector<double>& initial_state_estimate,
    const boost::numeric::ublas::matrix<double>& observation,
    const boost::numeric::ublas::matrix<double>& state_transition
  );

  ///Obtain the (estimated) measurement noise ('R')
  const boost::numeric::ublas::matrix<double>& GetEstimatedMeasurementNoise() const
    { return m_estimated_measurement_noise; }

  ///P: The initial estimation error covariance estimate
  const boost::numeric::ublas::matrix<double>& GetInitialCovarianceEstimate() const
    { return m_initial_covariance_estimate; }

  ///Obtain the process noise covariance ('Q')
  const boost::numeric::ublas::matrix<double>& GetEstimatedProcessNoiseCovariance() const
    { return m_estimated_process_noise_covariance; }

  ///Obtain the Kalman filter type as an enum
  KalmanFilterType GetType() const { return KalmanFilterType::standard; }

  ///Check if two parameter sets are equal with a fuzzy compare
  static bool IsAboutEqual(const StandardKalmanFilterParameters& lhs, const StandardKalmanFilterParameters& rhs);

  ///Obtain the version of this class
  static const std::string GetVersion();

  ///Obtain the version history of this class
  static const std::vector<std::string> GetVersionHistory();

  ///Check if this parameter set has a certain type of KalmanFilterParameter
  static bool HasParameterType(const KalmanFilterParameterType type);

  private:
  ///Can only be deleted by boost::checked_delete
  ~StandardKalmanFilterParameters() {}
  friend void boost::checked_delete<>(StandardKalmanFilterParameters*);

  ///R: Estimated measurement noise
  const boost::numeric::ublas::matrix<double> m_estimated_measurement_noise;

  ///Q: The estimated process noise covariance
  const boost::numeric::ublas::matrix<double> m_estimated_process_noise_covariance;

  ///P: The initial estimation error covariance estimate
  const boost::numeric::ublas::matrix<double> m_initial_covariance_estimate;
};

#endif // STANDARDKALMANFILTERPARAMETERS_H

#ifndef QTKALMANFILTERERMODEL_H
#define QTKALMANFILTERERMODEL_H

#include "qtublasmatrixdoublemodel.h"
#include "qtublasvectordoublemodel.h"
#include "qtstdvectorfunctionmodel.h"
#include "qtstdvectorstringmodel.h"

//struct QtUblasMatrixDoubleModel;
typedef QtUblasMatrixDoubleModel ControlModel;
typedef QtUblasMatrixDoubleModel EstimatedMeasurementNoiseModel;
typedef QtUblasMatrixDoubleModel EstimatedOptimalKalmanGainModel;
typedef QtUblasMatrixDoubleModel EstimatedProcessNoiseCovarianceModel;
typedef QtUblasMatrixDoubleModel InitialCovarianceEstimateModel;
typedef QtUblasMatrixDoubleModel ObservationModel;
typedef QtUblasMatrixDoubleModel StateTransitionModel;

//struct QtStdVectorDoubleModel;
typedef QtUblasVectorDoubleModel InitialStateEstimateModel;
typedef QtUblasVectorDoubleModel InitialStateRealModel;
typedef QtUblasVectorDoubleModel RealMeasurementNoiseModel;
typedef QtUblasVectorDoubleModel RealProcessNoiseModel;

//struct QtStdVectorFunctionModel;
typedef QtStdVectorFunctionModel InputModel;

//struct QtStdVectorStringModel;
typedef QtStdVectorStringModel StateNamesModel;


#endif // QTKALMANFILTERERMODEL_H

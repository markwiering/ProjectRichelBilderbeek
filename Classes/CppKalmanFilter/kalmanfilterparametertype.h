#ifndef KALMANFILTERPARAMETERTYPE_H
#define KALMANFILTERPARAMETERTYPE_H

#include <vector>

///The matrix/vector types/names of Kalman filter parameters
enum class KalmanFilterParameterType
{
  control,
  estimated_measurement_noise,
  estimated_optimal_kalman_gain,
  estimated_process_noise_covariance,
  initial_covariance_estimate,
  initial_state_estimate,
  observation,
  state_transition,
  n_parameters //Must be last element, used in debugging
};

bool operator<(const KalmanFilterParameterType lhs, const KalmanFilterParameterType rhs);
bool operator==(const KalmanFilterParameterType lhs, const KalmanFilterParameterType rhs);
bool operator!=(const KalmanFilterParameterType lhs, const KalmanFilterParameterType rhs);

#endif // KALMANFILTERPARAMETERTYPE_H

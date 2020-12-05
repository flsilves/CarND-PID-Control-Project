#include "PID.h"

/**
 * TODO: Complete the PID class. You may add any additional desired functions.
 */

PID::PID() {}

PID::~PID() {}

void PID::Init(double Kp_, double Ki_, double Kd_) {
  Kp = Kp_;
  Ki = Ki_;
  Kd = Kd_;

  i_error = 0.0;
  d_error = 0.0;
  p_error = 0.0;
}

void PID::UpdateError(double cte) {
  i_error = cte + p_error;
  d_error = cte - p_error;
  p_error = cte;
}

double PID::TotalError() {
  double p = -Kp * p_error;
  double d = -Kd * d_error;
  double i = -Ki * i_error;

  double steer_value = p + d + i;
  return steer_value;
}
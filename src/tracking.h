//
// Created by James Luo on 20/10/17.
//

#ifndef KALMANFILTER_TRACKING_H
#define KALMANFILTER_TRACKING_H

#include "measurement_package.h"
#include <vector>
#include <string>
#include <fstream>
#include "kalman_filter.h"

class Tracking {
 public:
  Tracking();
  virtual ~Tracking();
  void ProcessMeasurement(const MeasurementPackage &measurement_pack);
  KalmanFilter kf_;

 private:
  bool is_initialized_;
  int64_t previous_timestamp_;

  //acceleration noise components
  float noise_ax;
  float noise_ay;

};


#endif //KALMANFILTER_TRACKING_H

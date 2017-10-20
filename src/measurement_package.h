//
// Created by James Luo on 20/10/17.
//

#ifndef KALMANFILTER_MEASUREMENT_PACKAGE_H
#define KALMANFILTER_MEASUREMENT_PACKAGE_H


#include "Eigen/Dense"

class MeasurementPackage {
 public:
  int64_t timestamp_;

  enum SensorType {
    LASER, RADAR
  } sensor_type_;

  Eigen::VectorXd raw_measurements_;

};

#endif //KALMANFILTER_MEASUREMENT_PACKAGE_H

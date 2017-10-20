//
// Created by James Luo on 17/10/17.
//

#include <cstdio>
#include <iostream>
#include "kalman_filter_1d.h"
#include "Eigen/Dense"
#include <vector>

using namespace std;
using namespace Eigen;

void demo_usage_of_eigen();

//Kalman Filter variables
VectorXd x;	// object state
MatrixXd P;	// object covariance matrix
VectorXd u;	// external motion
MatrixXd F; // state transition matrix
MatrixXd H;	// measurement matrix
MatrixXd R;	// measurement covariance matrix
MatrixXd I; // Identity matrix
MatrixXd Q;	// process covariance matrix

vector<VectorXd> measurements;

void filter(VectorXd &x, MatrixXd &P);
void print(VectorXd &v);
void print(MatrixXd &m);

void kalman_1d() {
  printf("hello\n");

  demo_usage_of_eigen();

  /*
x is the mean state vector. For an extended Kalman filter, the mean state vector contains
   information about the object's position and velocity that you are tracking.
   It is called the "mean" state vector because position and velocity are represented
   by a gaussian distribution with mean x.
P is the state covariance matrix, which contains information about the uncertainty of the
   object's position and velocity. You can think of it as containing standard deviations.
k represents time steps. So x
​k
​​  refers to the object's position and velocity vector at time k.
The notation k+1∣k refers to the prediction step. At time k+1, you receive a sensor measurement.
   Before taking into account the sensor measurement to update your belief about the object's position and velocity,
   you predict where you think the object will be at time k+1. You can predict the position of the object
   at k+1 based on its position and velocity at time k. Hence x
​k+1∣k
​​  means that you have predicted where the object will be at k+1 but have not yet
   taken the sensor measurement into account.
x(​k+1)
​​  means that you have now predicted where the object will be at time k+1 and then used the
   sensor measurement to update the object's position and velocity.
   * **/
  x = VectorXd(2);
  x << 0, 0;

  //Uncertainty
  P = MatrixXd(2, 2);
  P << 1000, 0, 0, 1000;

  u = VectorXd(2);
  u << 0, 0;

  // state transition matrix
  F = MatrixXd(2, 2);
  F << 1, 1, 0, 1;

  // measurement matrix
  H = MatrixXd(1, 2);
  H << 1, 0;

  cout << "H, measurement matrix: " << H << endl;

  // measurement covariance matrix
  R = MatrixXd(1, 1);
  R << 1;

  I = MatrixXd::Identity(2, 2);

  // process covariance matrix
  Q = MatrixXd(2, 2);
  Q << 0, 0, 0, 0;

  //create a list of measurements
  VectorXd single_meas(1);
  single_meas << 1;
  measurements.push_back(single_meas);
  single_meas << 2;
  measurements.push_back(single_meas);
  single_meas << 3;
  measurements.push_back(single_meas);

  //call Kalman filter algorithm
  filter(x, P);
}

void filter(VectorXd &x, MatrixXd &P) {

  for (unsigned int n = 0; n < measurements.size(); ++n) {

    cout << "input x: " << endl << x << endl << " =============================================== new loop" << endl;

    VectorXd z = measurements[n];
    cout << "z, measurements: " << z << endl;
    //YOUR CODE HERE

    /*
     * KF Measurement update step
     */

    VectorXd y = z - H * x;
    cout << "y, z- H * x: " << y << endl;
    MatrixXd Ht = H.transpose();
    cout << "Ht H.transpose: " << Ht << endl;
    MatrixXd S = H * P * Ht + R;
    cout << "S = H * P * Ht + R: " << S << endl;
    MatrixXd Si = S.inverse();
    cout << "Si = S.inverse: " << Si << endl;
    MatrixXd K =  P * Ht * Si;
    cout << "K = P * Ht * Si: " << K << endl;

    //new state
    x = x + (K * y);
    cout << "new state, x = x + (K * y): " << x << endl;
    P = (I - K * H) * P;
    cout << "new state, P = (I - K * H) * P: " << P << endl;

    /*
     * KF Prediction step
     */
    x = F * x + u;
    MatrixXd Ft = F.transpose();
    P = F * P * Ft + Q;

    std::cout << "prediction x=F * x + u:" << std::endl <<  x << std::endl;
    std::cout << "prediction P=F * P * Ft + Q: " << std::endl <<  P << std::endl;
  }
}

void print(VectorXd &v) {
  cout << v << endl;
}

void print(MatrixXd &m) {
  cout << m << endl;
}

void demo_usage_of_eigen() {
  //you can create a  vertical vector of two elements with a command like this
  VectorXd my_vector(2);
  //you can use the so called comma initializer to set all the coefficients to some values
  my_vector << 10, 20;


  //and you can use the cout command to print out the vector
  cout << my_vector << endl;


  //the matrices can be created in the same way.
  //For example, This is an initialization of a 2 by 2 matrix
  //with the values 1, 2, 3, and 4
  MatrixXd my_matrix(2,2);
  my_matrix << 1, 2,
      3, 4;
  cout << my_matrix << endl;


  //you can use the same comma initializer or you can set each matrix value explicitly
  // For example that's how we can change the matrix elements in the second row
  my_matrix(1,0) = 11;    //second row, first column
  my_matrix(1,1) = 12;    //second row, second column
  cout << my_matrix << endl;


  //Also, you can compute the transpose of a matrix with the following command
  MatrixXd my_matrix_t = my_matrix.transpose();
  cout << my_matrix_t << endl;


  //And here is how you can get the matrix inverse
  MatrixXd my_matrix_i = my_matrix.inverse();
  cout << my_matrix_i << endl;


  //For multiplying the matrix m with the vector b you can write this in one line as let’s say matrix c equals m times v.
  //
  MatrixXd another_matrix;
  another_matrix = my_matrix*my_vector;
  cout << another_matrix << endl;
}

//
// Created by James Luo on 20/10/17.
//

#ifndef KALMANFILTER_ENTRYPOINT_H_H
#define KALMANFILTER_ENTRYPOINT_H_H

#include "string.h"
using std::string;

int entryPoint2D();
int processFile(string fileName);

void jacobianMatrix();

#endif //KALMANFILTER_ENTRYPOINT_H_H

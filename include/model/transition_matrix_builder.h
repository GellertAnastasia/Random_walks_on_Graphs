#ifndef TRANSITION_MATRIX_BUILDER
#define TRANSITION_MATRIX_BUILDER

#include <Eigen/Dense>
using Matrix = Eigen::MatrixXd;
using Vector = Eigen::VectorXd;

#include "graph_model.h"

class TransitionMatrixBuilder {
public:
    Matrix build(GraphModel& model);
};

#endif
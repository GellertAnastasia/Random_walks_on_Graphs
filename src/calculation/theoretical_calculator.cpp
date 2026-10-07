#include "theoretical_calculator.h"

TheoreticalCalculator::TheoreticalCalculator(const AbsorbingChain& chain) {
    const Matrix& P = chain.getTransitionMatrix();

    const auto& transient = chain.getTransientStates();
    const auto& absorbing = chain.getAbsorbingStates();

    Q = Matrix(transient.size(), transient.size());
    for (size_t i = 0; i < transient.size(); ++i) {
        for (size_t j = 0; j < transient.size(); ++j) {
            Q(i, j) = P(transient[i], transient[j]);
        }
    }

    R = Matrix(transient.size(), absorbing.size());
    for (size_t i = 0; i < transient.size(); ++i) {
        for (size_t j = 0; j < absorbing.size(); ++j) {
            R(i, j) = P(transient[i], absorbing[j]);
        }
    }

    Matrix I = Matrix::Identity(Q.rows(), Q.cols());
    N = (I - Q).inverse();

    B = N * R;

    mean = N * Vector::Ones(N.rows());

    Vector meanSq = mean.array().square();
    variance = (2 * N - I) * mean - meanSq;
}

const Matrix& TheoreticalCalculator::getQ() const {
    return Q;
}
const Matrix& TheoreticalCalculator::getR() const {
    return R;
}
const Matrix& TheoreticalCalculator::getN() const {
    return N;
}
const Matrix& TheoreticalCalculator::getB() const {
    return B;
}
const Vector& TheoreticalCalculator::getMean() const {
    return mean;
}
const Vector& TheoreticalCalculator::getVariance() const {
    return variance;
}
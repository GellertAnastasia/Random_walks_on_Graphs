#ifndef THEORETICAL_CALCULATOR
#define THEORETICAL_CALCULATOR

#include "absorbing_chain.h"

class TheoreticalCalculator {
private:
    Matrix Q;
    Matrix R;
    Matrix N;
    Matrix B;
    Vector mean;
    Vector variance;

public:
    TheoreticalCalculator(const AbsorbingChain& chain);

    const Matrix& getQ() const;
    const Matrix& getR() const;
    const Matrix& getN() const;
    const Matrix& getB() const;
    const Vector& getMean() const;
    const Vector& getVariance() const;
};

#endif
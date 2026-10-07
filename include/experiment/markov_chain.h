#ifndef MARKOV_CHAIN
#define MARKOV_CHAIN

#include "transition_matrix_builder.h"

class MarkovChain {
protected:
    Matrix transitionMatrix;

public:
    MarkovChain(const Matrix& transitionMatrix);

    const Matrix& getTransitionMatrix() const;
};

#endif
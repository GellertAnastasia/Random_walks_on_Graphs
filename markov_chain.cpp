#include "markov_chain.h"

MarkovChain::MarkovChain(const Matrix& transitionMatrix) : transitionMatrix(transitionMatrix) {}

const Matrix& MarkovChain::getTransitionMatrix() const {
    return transitionMatrix;
}
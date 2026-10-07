#ifndef ABSORBING_CHAIN
#define ABSORBING_CHAIN

#include "markov_chain.h"

#include <vector>

class AbsorbingChain : public MarkovChain {
private:
    std::vector<int> transientStates;
    std::vector<int> absorbingStates;

public:
    AbsorbingChain(GraphModel& model);

    const std::vector<int>& getTransientStates() const;
    const std::vector<int>& getAbsorbingStates() const;
};

#endif
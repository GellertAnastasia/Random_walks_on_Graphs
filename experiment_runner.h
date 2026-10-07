#ifndef EXPERIMENT_RUNNER
#define EXPERIMENT_RUNNER

#include "absorbing_chain.h"

#include <string>

class ExperimentRunner {
public:
    void run(const AbsorbingChain& chain, int initialState, int simulations,
             const std::string& filename);
};

#endif
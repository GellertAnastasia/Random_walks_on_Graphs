#ifndef SIMULATOR
#define SIMULATOR

#include "graph_model.h"
#include "path.h"

#include <random>
#include <vector>

class AbsorbingChain;

class Simulator {
private:
    const Graph* graph = nullptr;
    std::vector<bool> isAbsorbing;
    std::vector<std::discrete_distribution<int>> precomputedDistr;
    std::mt19937 generator;

public:
    Simulator(const GraphModel& model);
    Simulator(const AbsorbingChain& chain);

    Path run(int initialState);
};

#endif
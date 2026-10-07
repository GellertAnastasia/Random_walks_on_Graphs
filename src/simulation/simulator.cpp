#include "simulator.h"

#include "absorbing_chain.h"

Simulator::Simulator(const GraphModel& model)
    : graph(&model.getGraph()), generator(std::random_device{}()) {
    int n = static_cast<int>(graph->getCountVertices());
    isAbsorbing.assign(n, false);
    int cheese = model.getCheese();
    int cat = model.getCat();
    if (cheese >= 0 && cheese < n)
        isAbsorbing[cheese] = true;
    if (cat >= 0 && cat < n)
        isAbsorbing[cat] = true;
}

Simulator::Simulator(const AbsorbingChain& chain)
    : graph(nullptr), generator(std::random_device{}()) {
    int n = static_cast<int>(chain.getTransitionMatrix().rows());
    isAbsorbing.assign(n, false);
    for (int absorbing : chain.getAbsorbingStates()) {
        if (absorbing >= 0 && absorbing < n) {
            isAbsorbing[absorbing] = true;
        }
    }

    precomputedDistr.reserve(n);
    for (int i = 0; i < n; ++i) {
        Vector row = chain.getTransitionMatrix().row(i);
        std::vector<double> weights(row.data(), row.data() + row.size());
        precomputedDistr.emplace_back(weights.begin(), weights.end());
    }
}

Path Simulator::run(int initialState) {
    int currentState = initialState;
    int steps = 0;

    if (graph != nullptr) {
        while (!isAbsorbing[currentState]) {
            const auto& neighbors = graph->getNeighbors(currentState);
            size_t deg = neighbors.size();
            size_t nextIdx = 0;
            if (deg > 1) {
                std::uniform_int_distribution<size_t> dist(0, deg - 1);
                nextIdx = dist(generator);
            }
            currentState = neighbors[nextIdx];
            ++steps;
        }
    } else {
        while (!isAbsorbing[currentState]) {
            currentState = precomputedDistr[currentState](generator);
            ++steps;
        }
    }

    return Path(steps, currentState);
}
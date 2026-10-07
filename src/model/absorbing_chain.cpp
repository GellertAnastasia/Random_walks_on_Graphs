#include "absorbing_chain.h"

AbsorbingChain::AbsorbingChain(GraphModel& model)
    : MarkovChain(TransitionMatrixBuilder().build(model)) {
    int cat = model.getCat();
    int cheese = model.getCheese();

    absorbingStates = {cheese, cat};

    for (int i = 0; i < model.getGraph().getCountVertices(); ++i) {
        if (i != cat && i != cheese) {
            transientStates.push_back(i);
        }
    }
}

const std::vector<int>& AbsorbingChain::getTransientStates() const {
    return transientStates;
}

const std::vector<int>& AbsorbingChain::getAbsorbingStates() const {
    return absorbingStates;
}
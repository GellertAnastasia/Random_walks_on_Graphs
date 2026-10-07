#include "path.h"

Path::Path(int absorptionTime, int lastState)
    : absorptionTime(absorptionTime), lastState(lastState) {}

void Path::addState(int state) {
    states.push_back(state);
    absorptionTime = static_cast<int>(states.size()) - 1;
    lastState = state;
}

const std::vector<int>& Path::getStates() const {
    return states;
}

int Path::getAbsorptionTime() const {
    return absorptionTime;
}

int Path::getLastState() const {
    return lastState;
}
#ifndef PATH
#define PATH

#include <vector>

class Path {
private:
    std::vector<int> states;
    int absorptionTime = 0;
    int lastState = -1;

public:
    Path() = default;
    Path(int absorptionTime, int lastState);

    void addState(int state);
    const std::vector<int>& getStates() const;

    int getAbsorptionTime() const;
    int getLastState() const;
};

#endif
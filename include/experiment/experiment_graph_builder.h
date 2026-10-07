#ifndef EXPERIMENT_GRAPH_BUILDER
#define EXPERIMENT_GRAPH_BUILDER

#include "graph_model.h"

#include <string>

class ExperimentGraphBuilder {
public:
    GraphModel createSizeGraph(int size);
    GraphModel deadEndExperimentGraph(int numberOfDeadEnds, int deadEndLength);
    GraphModel cycleExperimentGraph(int cycleLength);
    GraphModel createJointGraph(const std::string& topology, int addedVertices);
};

#endif
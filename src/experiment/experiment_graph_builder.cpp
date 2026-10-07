#include "experiment_graph_builder.h"

#include "graph_generator.h"

GraphModel ExperimentGraphBuilder::createSizeGraph(int size) {
    GraphGenerator generator;
    return generator.createSegment(size);
}

GraphModel ExperimentGraphBuilder::deadEndExperimentGraph(int numberOfDeadEnds, int deadEndLength) {
    GraphGenerator generator;
    const int firstBranchVertex = 2;
    GraphModel model = generator.createSegment(15);

    for (int i = 0; i < numberOfDeadEnds; ++i) {
        int startVertex = firstBranchVertex + i;
        if (startVertex >= model.getCat()) {
            break;
        }

        generator.addDeadEnd(model, startVertex, deadEndLength);
    }

    return model;
}

GraphModel ExperimentGraphBuilder::cycleExperimentGraph(int cycleLength) {
    GraphGenerator generator;
    GraphModel model = generator.createSegment(7);
    generator.addCycle(model, 3, cycleLength);

    return model;
}

GraphModel ExperimentGraphBuilder::createJointGraph(const std::string& topology,
                                                    int addedVertices) {
    GraphGenerator generator;
    GraphModel model = generator.createSegment(7);

    if (topology == "dead_end") {
        generator.addDeadEndBranch(model, 3, addedVertices);
    } else if (topology == "petal_cycle") {
        generator.addPetalCycle(model, 3, addedVertices);
    } else if (topology == "bypass_route") {
        generator.addBypassRoute(model, 2, 4, addedVertices);
    }

    return model;
}
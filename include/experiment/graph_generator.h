#ifndef GRAPH_GENERATOR
#define GRAPH_GENERATOR

#include "graph_model.h"

class GraphGenerator {
public:
    GraphModel createSegment(int length);
    void addDeadEnd(GraphModel& model, int startVertex, int length);
    void addCycle(GraphModel& model, int startVertex, int length);

    void addDeadEndBranch(GraphModel& model, int startVertex, int numVertices);
    void addPetalCycle(GraphModel& model, int startVertex, int numVertices);
    void addBypassRoute(GraphModel& model, int u, int v, int numVertices);
};

#endif
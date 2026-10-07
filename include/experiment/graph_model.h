#ifndef GRAPH_MODEL
#define GRAPH_MODEL

#include "graph.h"

class GraphModel {
private:
    Graph graph;
    int cheese;
    int cat;

public:
    GraphModel(Graph graph, int cheese, int cat);

    Graph& getGraph();
    const Graph& getGraph() const;
    int getCheese() const;
    int getCat() const;
};

#endif
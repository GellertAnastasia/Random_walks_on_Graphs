#include "graph_model.h"

GraphModel::GraphModel(Graph graph, int cheese, int cat) : graph(graph), cheese(cheese), cat(cat) {}

Graph& GraphModel::getGraph() {
    return graph;
}

const Graph& GraphModel::getGraph() const {
    return graph;
}

int GraphModel::getCheese() const {
    return cheese;
}

int GraphModel::getCat() const {
    return cat;
}
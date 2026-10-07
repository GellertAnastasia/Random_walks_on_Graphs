#include "graph.h"

int Graph::addVertex() {
    neighbors.push_back({});
    return neighbors.size() - 1;
}

void Graph::addNeighbor(int u, int v) {
    neighbors[u].push_back(v);
    neighbors[v].push_back(u);
}

const std::vector<int>& Graph::getNeighbors(int v) const {
    return neighbors[v];
}

size_t Graph::getCountVertices() const {
    return neighbors.size();
}
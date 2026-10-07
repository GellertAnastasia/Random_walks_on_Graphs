#ifndef GRAPH
#define GRAPH

#include <vector>

class Graph {
private:
    std::vector<std::vector<int>> neighbors;

public:
    Graph() = default;

    int addVertex();
    void addNeighbor(int u, int v);
    const std::vector<int>& getNeighbors(int v) const;
    size_t getCountVertices() const;
};

#endif
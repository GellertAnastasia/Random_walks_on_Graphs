#include "graph_generator.h"

GraphModel GraphGenerator::createSegment(int length) {
    Graph graph;
    int previous = graph.addVertex();

    for (int i = 1; i < length; ++i) {
        int current = graph.addVertex();
        graph.addNeighbor(previous, current);
        previous = current;
    }
    return GraphModel(graph, 0, length - 1);
}

void GraphGenerator::addDeadEnd(GraphModel& model, int startVertex, int length) {
    Graph& graph = model.getGraph();
    int previous = startVertex;

    for (int i = 1; i < length; ++i) {
        int current = graph.addVertex();
        graph.addNeighbor(previous, current);
        previous = current;
    }
}

void GraphGenerator::addCycle(GraphModel& model, int startVertex, int length) {
    Graph& graph = model.getGraph();
    int previous = startVertex;

    for (int i = 1; i < length; ++i) {
        int current = graph.addVertex();
        graph.addNeighbor(previous, current);
        previous = current;
    }
    graph.addNeighbor(previous, startVertex);
}

void GraphGenerator::addDeadEndBranch(GraphModel& model, int startVertex, int numVertices) {
    Graph& graph = model.getGraph();
    int previous = startVertex;
    for (int i = 0; i < numVertices; ++i) {
        int current = graph.addVertex();
        graph.addNeighbor(previous, current);
        previous = current;
    }
}

void GraphGenerator::addPetalCycle(GraphModel& model, int startVertex, int numVertices) {
    if (numVertices <= 0)
        return;
    Graph& graph = model.getGraph();
    int first = graph.addVertex();
    graph.addNeighbor(startVertex, first);
    int previous = first;
    for (int i = 1; i < numVertices; ++i) {
        int current = graph.addVertex();
        graph.addNeighbor(previous, current);
        previous = current;
    }
    graph.addNeighbor(previous, startVertex);
}

void GraphGenerator::addBypassRoute(GraphModel& model, int u, int v, int numVertices) {
    if (numVertices <= 0)
        return;
    Graph& graph = model.getGraph();
    int first = graph.addVertex();
    graph.addNeighbor(u, first);
    int previous = first;
    for (int i = 1; i < numVertices; ++i) {
        int current = graph.addVertex();
        graph.addNeighbor(previous, current);
        previous = current;
    }
    graph.addNeighbor(previous, v);
}
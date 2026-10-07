#include "transition_matrix_builder.h"

Matrix TransitionMatrixBuilder::build(GraphModel& model) {
    const Graph& graph = model.getGraph();
    int cheese = model.getCheese();
    int cat = model.getCat();
    int n = graph.getCountVertices();

    Matrix P = Matrix::Zero(n, n);
    for (int i = 0; i < n; ++i) {
        if (i == cheese || i == cat) {
            P(i, i) = 1;
        } else {
            const std::vector<int>& neighbors = graph.getNeighbors(i);
            double probability = 1.0 / neighbors.size();
            for (int j : neighbors) {
                P(i, j) = probability;
            }
        }
    }
    return P;
}
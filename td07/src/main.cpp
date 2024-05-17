#include <iostream>
#include "graph.hpp"

std::vector<std::vector<float>> adjacency_matrix{
    // 0  1  2
    {0.f, 1.f, 2.f},  // 0
    {0.f, 0.f, 3.f},  // 1
    {0.f, 0.f, 0.f}}; // 2

int main()
{
    Graph::WeightedGraph graph_1 = Graph::adjacency_list_from_adjacency_matrix(adjacency_matrix);
    Graph::WeightedGraph graph_2{};
    graph_2.add_vertex(0);
    graph_2.add_vertex(1);
    graph_2.add_vertex(2);
    graph_2.add_directed_edge(0, 1, 1.f);
    graph_2.add_directed_edge(0, 2, 2.f);
    graph_2.add_directed_edge(1, 2, 3.f);

    if (graph_1 == graph_2)
    {
        std::cout << "les mêmes";
    }
    else
    {
        std::cout << "pas les mêmes";
    }
}
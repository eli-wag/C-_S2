#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdlib>
#include <stack>
#include <queue>

#include "graph.hpp"

void Graph::WeightedGraph::add_vertex(int const id)
{
    if (adjacency_list.find(id) != adjacency_list.end())
    {
        return;
    }
    adjacency_list.insert({id, {}}); // il sait qu'il a besoin d'un vecteur pour compléter la pair car c'est comme ça qu'a été défini adjacency_list
}

void Graph::WeightedGraph::add_directed_edge(int const from, int const to, float const weight)
{
    if (adjacency_list.find(from) == adjacency_list.end())
    {
        return;
    }
    if (adjacency_list.find(to) != adjacency_list.end())
    {
        add_vertex(to);
    }
    adjacency_list[from].push_back(Graph::WeightedGraphEdge{to, weight});
}

void Graph::WeightedGraph::add_undirected_edge(int const from, int const to, float const weight)
{
    add_directed_edge(from, to, weight);
    add_directed_edge(to, from, weight);
}

Graph::WeightedGraph Graph::adjacency_list_from_adjacency_matrix(std::vector<std::vector<float>> const &adjacency_matrix)
{
    WeightedGraph graph{};
    for (int i{0}; i < adjacency_matrix.size(); i++)
    {
        graph.add_vertex(i);
        for (size_t j = 0; j < adjacency_matrix[i].size(); j++)
        {
            if (adjacency_matrix[i][j] == 0)
            {
                continue;
            }
            graph.add_directed_edge(i, j, adjacency_matrix[i][j]);
        }
    }
    return graph;
}

void Graph::WeightedGraph::print_DFS(int const start) const
{
    std::unordered_map<int, bool> visited{};
    std::stack<int> stack{};
    stack.push(start);
    while (!stack.empty())
    {
        int vertex{stack.top()};
        stack.pop();
        if (!visited[vertex])
        {
            visited[vertex] = true;
        }
        for (const auto &edge : adjacency_list.at(vertex))
        {
            if (!visited[edge.to])
            {
                stack.push(edge.to);
            }
        }
    }
}

void Graph::WeightedGraph::print_BFS(int const start) const
{
    std::unordered_map<int, bool> visited{};
    std::queue<int> queue{};
    queue.push(start);
    while (!queue.empty())
    {
        int vertex{queue.front()};
        queue.pop();
        if (!visited[vertex])
        {
            visited[vertex] = true;
        }
        for (const auto &edge : adjacency_list.at(vertex))
        {
            if (!visited[edge.to])
            {
                queue.push(edge.to);
            }
        }
    }
}
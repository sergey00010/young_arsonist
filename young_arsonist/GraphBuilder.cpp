#include "GraphBuilder.h"

int GraphBuilder::getVertex(int x, int y, Graph& graph) {

    //Finding an existing vertex
    for (int i = 0; i < graph.count_vertex; ++i) {
        if (graph.list[i].x == x && graph.list[i].y == y) {
            return i;
        }
    }

    //Adding a new vertex
    graph.list[graph.count_vertex] = { x, y };
    for (int i = 0; i < graph.count_vertex; ++i) {
        //The weights between the new node and all existing nodes are set to NONE_VALUE (there is no edge)
        graph.weight[i][graph.count_vertex] = NONE_VALUE;
        graph.weight[graph.count_vertex][i] = NONE_VALUE;
    }
    //The weight from the new vertex to itself is set to 0, 
    //since the distance from the vertex to itself is zero.
    graph.weight[graph.count_vertex][graph.count_vertex] = 0;
    return graph.count_vertex++;
}

void GraphBuilder::addEdge(int x1, int y1, int x2, int y2, long int time, Graph& graph) {
    //Getting vertex indices
    int v1 = getVertex(x1, y1, graph);
    int v2 = getVertex(x2, y2, graph);

    //Adding an edge
    graph.weight[v1][v2] = time;
    graph.weight[v2][v1] = time;
}

Graph GraphBuilder::build(const std::vector<Match>& matches) {
    Graph graph;
    for (const auto& match : matches) {
        addEdge(match.x1 * 2, match.y1 * 2, match.x1 + match.x2, match.y1 + match.y2, match.time, graph);
        addEdge(match.x1 + match.x2, match.y1 + match.y2, match.x2 * 2, match.y2 * 2, match.time, graph);
    }
    return graph;
}
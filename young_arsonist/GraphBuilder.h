#ifndef GRAPHBUILDER_H
#define GRAPHBUILDER_H

#include <vector>
#include "MatchReader.h"

const int max_matches = 40;
const int masx_vertex = max_matches * 2;
const long int NONE_VALUE = 10000001L;

//A structure that contains a graph vertex with coordinates
struct Vertex {
    int x, y;
};


//the structure that contains a graph. It contains the number of vertices count_vertex, a weight matrix weight, and a list of vertices list
struct Graph {
    int count_vertex = 0;
    long int weight[masx_vertex][masx_vertex];
    Vertex list[masx_vertex];
};

class GraphBuilder {
public:
    //This method builds a graph based on a list of matches. For each match, two edges are added to the graph.
    static Graph build(const std::vector<Match>& matches);

private:
    /*
    This method returns the index of the vertex with coordinates (x, y). 
    If a vertex with those coordinates already exists, its index is returned.
    If not, a new vertex is created and its index is returned.
    */
    static int getVertex(int x, int y, Graph& graph);

    //This method adds an edge between two vertices with weight time
    static void addEdge(int x1, int y1, int x2, int y2, long int time, Graph& graph);
};

#endif
#ifndef GRAPHBUILDER_H
#define GRAPHBUILDER_H

#include <vector>
#include "MatchReader.h"

const int max_matches = 40;
const int masx_vertex = max_matches * 2;
const long int NONE_VALUE = 10000001L;

struct Vertex {
    int x, y;
};

struct Graph {
    int count_vertex = 0;
    long int weight[masx_vertex][masx_vertex];
    Vertex list[masx_vertex];
};

class GraphBuilder {
public:
    static Graph build(const std::vector<Match>& matches);

private:
    static int getVertex(int x, int y, Graph& graph);
    static void addEdge(int x1, int y1, int x2, int y2, long int time, Graph& graph);
};

#endif
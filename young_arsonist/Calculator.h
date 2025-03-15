#ifndef RESULTCALCULATOR_H
#define RESULTCALCULATOR_H

#include "GraphBuilder.h"

//A structure that contains a result that contains the coordinates of a point (x, y) and time
struct Result {
    int x, y;
    double time;
};

class Calculator {
public:
    /*
    This method computes the result using the Floyd-Warshall algorithm to find the shortest paths between all pairs of vertices.
    */
    static Result calculate(const Graph& graph);

private:
    //This method uses the Floyd-Warshall algorithm to find the shortest paths between all pairs of vertices.
    static void floydWarshall(double distance[masx_vertex][masx_vertex], int count);
    //This method calculates the time for a particular vertex p, taking into account all possible paths and their weights.
    static double getTimeAt(int p, const Graph& graph, double distance[masx_vertex][masx_vertex]);
};

#endif
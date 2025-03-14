#ifndef RESULTCALCULATOR_H
#define RESULTCALCULATOR_H

#include "GraphBuilder.h"

struct Result {
    int x, y;
    double time;
};

class Calculator {
public:
    static Result calculate(const Graph& graph);

private:
    static void floydWarshall(double distance[masx_vertex][masx_vertex], int count);
    static double getTimeAt(int p, const Graph& graph, double distance[masx_vertex][masx_vertex]);
};

#endif
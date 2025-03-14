#include "Calculator.h"
#include <iostream>

void Calculator::floydWarshall(double distance[masx_vertex][masx_vertex], int count) {
    for (int k = 0; k < count; ++k) {
        for (int i = 0; i < count; ++i) {
            if (distance[i][k] < NONE_VALUE) {
                for (int j = 0; j < count; ++j) {
                    if (distance[i][k] + distance[k][j] < distance[i][j]) {
                        distance[i][j] = distance[i][k] + distance[k][j];
                    }
                }
            }
        }
    }

    for (int i = 0; i < count; ++i) {
        if (distance[0][i] == NONE_VALUE) {
            std::cerr << "Incorrect data format: incoherent figure\n";
            exit(1);
        }
    }
}

double Calculator::getTimeAt(int p, const Graph& graph, double distance[masx_vertex][masx_vertex]) {
    double currentTime = 0;
    for (int i = 0; i < graph.count_vertex; ++i) {
        if (distance[p][i] > currentTime) {
            currentTime = distance[p][i];
        }
    }
    for (int i = 0; i < graph.count_vertex; ++i) {
        for (int j = i + 1; j < graph.count_vertex; ++j) {
            if (graph.weight[i][j] < NONE_VALUE) {
                if ((distance[p][i] < (distance[p][j] + static_cast<double>(graph.weight[i][j]))) &&
                    (distance[p][j] < (distance[p][i] + static_cast<double>(graph.weight[i][j])))) {
                    double currentWeight;
                    if (distance[p][i] < distance[p][j]) {
                        currentWeight = distance[p][j] + (static_cast<double>(graph.weight[i][j]) - (distance[p][j] - distance[p][i])) / 2;
                    }
                    else {
                        currentWeight = distance[p][i] + (static_cast<double>(graph.weight[i][j]) - (distance[p][i] - distance[p][j])) / 2;
                    }
                    if (currentWeight > currentTime) {
                        currentTime = currentWeight;
                    }
                }
            }
        }
    }
    return currentTime;
}

Result Calculator::calculate(const Graph& graph) {
    double distance[masx_vertex][masx_vertex];
    for (int i = 0; i < graph.count_vertex; ++i) {
        for (int j = 0; j < graph.count_vertex; ++j) {
            distance[i][j] = static_cast<double>(graph.weight[i][j]);
        }
    }

    floydWarshall(distance, graph.count_vertex);

    Result result = { 0, 0, NONE_VALUE };
    for (int i = 0; i < graph.count_vertex; ++i) {
        if (graph.list[i].x % 2 == 0 && graph.list[i].y % 2 == 0) {
            double currentTime = getTimeAt(i, graph, distance);
            if (currentTime < result.time) {
                result.time = currentTime;
                result.x = graph.list[i].x / 2;
                result.y = graph.list[i].y / 2;
            }
        }
    }
    return result;
}
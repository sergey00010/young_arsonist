#include <map>
#include <iostream>

#include "MatchReader.h"
#include "GraphBuilder.h"
#include "Calculator.h"
#include "ResultWriter.h"


/*
created by Sergey Kuzmenko 

young arsonist
the program is needed to find the minimum burning time of matches

MatchReader is responsible for reading data
GraphBuilder is responsible for constructing the graph
Calculator is responsible for calculating the result based on the constructed graph
ResultWriter is responsible for writing the result to the output file
Vertex stores information about a graph vertex
Graph stores information about the graph, including a list of vertices and a weight matrix
Result stores the result of calculations
*/


//function that reads parameters from .env file
std::map<std::string, std::string> readEnvFile(const std::string& filePath) {
    std::map<std::string, std::string> envMap;
    std::ifstream envFile(filePath);
    std::string line;

    if (!envFile.is_open()) {
        std::cerr << "error. file .env don't open" << std::endl;
        exit(1);
    }

    while (std::getline(envFile, line)) {
        size_t delimiterPos = line.find('=');
        if (delimiterPos != std::string::npos) {
            std::string key = line.substr(0, delimiterPos);
            std::string value = line.substr(delimiterPos + 1);
            envMap[key] = value;
        }
    }

    envFile.close();
    return envMap;
}


int main() {
    const std::map<std::string, std::string> env = readEnvFile(".env");
    auto matches = MatchReader::read(env.at("file_in"));
    auto graph = GraphBuilder::build(matches);
    auto result = Calculator::calculate(graph);
    ResultWriter::write(result, env.at("file_out"));
    char i;
    std::cin >> i;
    return 0;
}
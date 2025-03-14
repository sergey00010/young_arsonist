#include "MatchReader.h"
#include "GraphBuilder.h"
#include "Calculator.h"
#include "ResultWriter.h"
#include <map>

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
    const std::map<std::string, std::string> env = readEnvFile("D:\\Documents\\projects\\young_arsonist\\young_arsonist\\x64\\Debug\\.env");
    auto matches = MatchReader::read(env.at("file_in"));
    auto graph = GraphBuilder::build(matches);
    auto result = Calculator::calculate(graph);
    ResultWriter::write(result, env.at("file_out"));
    return 0;
}
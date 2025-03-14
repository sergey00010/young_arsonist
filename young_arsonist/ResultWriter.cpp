#include "ResultWriter.h"
#include <fstream>
#include <iostream>
#include <cerrno>

void ResultWriter::write(const Result& result, const std::string& file_out) {
    std::ofstream fout(file_out);
    if (!fout) {
        perror("write: fopen() ");
        exit(errno);
    }
    fout << result.x << " " << result.y << "\n";
    fout.precision(2);
    fout << std::fixed << result.time / 2 << "\n";
    fout.close();

    std::cout << "________________________" << std::endl;
    std::cout << result.x << " " << result.y << std::endl;
    std::cout.precision(2);
    std::cout << std::fixed << result.time / 2 << std::endl;
}
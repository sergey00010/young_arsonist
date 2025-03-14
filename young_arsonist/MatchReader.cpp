#include "MatchReader.h"

std::vector<Match> MatchReader::read(const std::string& file_in) {
    std::ifstream fin(file_in);
    if (!fin) {
        perror("read: fopen() ");
        exit(errno);
    }

    int len;
    fin >> len;
    std::cout << len << std::endl;

    std::vector<Match> matches(len);
    for (int i = 0; i < len; ++i) {
        fin >> matches[i].x1 >> matches[i].y1 >> matches[i].x2 >> matches[i].y2 >> matches[i].time;

        std::cout << matches[i].x1 <<" " << matches[i].y1 << " " << matches[i].x2 << " " << matches[i].y2 << " " << matches[i].time << std::endl;
    }
    fin.close();
    return matches;
}
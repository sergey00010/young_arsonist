#ifndef MATCHREADER_H
#define MATCHREADER_H

#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <cerrno>
#include <iostream>

struct Match {
    int x1, y1, x2, y2;
    long int time;
};

class MatchReader {
public:
    static std::vector<Match> read(const std::string &file_in);
};

#endif
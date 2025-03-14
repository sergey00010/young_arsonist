#ifndef RESULTWRITER_H
#define RESULTWRITER_H

#include <string>

#include "Calculator.h"

class ResultWriter {
public:
    static void write(const Result& result, const std::string &file_out);
};

#endif 
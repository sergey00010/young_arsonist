#ifndef RESULTWRITER_H
#define RESULTWRITER_H

#include <string>

#include "Calculator.h"

class ResultWriter {
public:
    //This method writes the result to the output file.
    static void write(const Result& result, const std::string &file_out);
};

#endif 
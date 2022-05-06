#pragma once

#include <array>
#include <cstdio>
#include <iostream>
#include <memory>
#include <stdexcept>
#include <string>
#include <sstream>
#include <vector>

#include "lut.hpp"

class SAT {
public:
    static std::string exec(const char* cmd);
    static LUT GetResult(std::string cmd_output, int h, int l);
};

vector<std::string> splitString(std::string str, std::string delimiter = " ");
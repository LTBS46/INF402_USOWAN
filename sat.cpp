#include "sat.hpp"

std::string SAT::exec(const char* cmd) {
    std::array<char, 128> buffer;
    std::string result;
    std::unique_ptr<FILE, decltype(&pclose)> pipe(popen(cmd, "r"), pclose);
    if (!pipe) {
        throw std::runtime_error("popen() failed!");
    }
    while (fgets(buffer.data(), buffer.size(), pipe.get()) != nullptr) {
        result += buffer.data();
    }
    return result;
}

LUT SAT::GetResult(std::string cmd_output, int h, int l) {
    std::stringstream ss(cmd_output);
    std::string line;

    while(std::getline(ss, line, '\n')) {
        char ch = line.at(0);
        if (ch == 's') {
            if (line.at(2) == 'U') {
                std::cout << "ERROR: Unsatisfiable grid" << std::endl;
                exit(-1);
            }
        }
        else if (ch == 'v') {
            break;
        }
    }

    
    LUT result = LUT(h, l);
    vector<std::string> str_result = splitString(line, " ");

    for (std::string s : str_result) {

        if (s == "v" || s == "0") {
            continue;
        } else {
            int index = stoi(s);

            result.SetIndex((index > 0 ? index - 1 : (index*-1) -1), (index > 0 ? true : false));
        }
    }

    return result;
}

vector<std::string> splitString(std::string str, std::string delimiter)
{
    vector<std::string> split;
    int start = 0;
    int end = str.find(delimiter);
    while (end != -1) {
        split.push_back(str.substr(start, end - start));
        start = end + delimiter.size();
        end = str.find(delimiter, start);
    }
    split.push_back(str.substr(start, end - start));

    return split;
}
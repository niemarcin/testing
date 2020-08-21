#include "ArgumentParser.hpp"

#include <algorithm>

ArgumentParser::ArgumentParser(int argc, char** argv) {
    argc_ = argc;
    argv_.reserve(argc_);
    for (int i = 0; i <argc_ ; ++i) {
        argv_.push_back(argv[i]);
    }
    appName_ = argv_[0];
}

bool ArgumentParser::cmdOptionExists(const std::string& option) const {
    return std::find(begin(argv_), end(argv_), option) != end(argv_);
}

bool ArgumentParser::argumentEndsWith(size_t argIndex, std::string const &ending) const {
    if (argv_[argIndex].length() < ending.length()) {
        return false;
    } 
    return (argv_[argIndex].substr(argv_[argIndex].length() - ending.length()) == ending);
}

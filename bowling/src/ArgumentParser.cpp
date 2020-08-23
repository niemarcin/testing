#include "ArgumentParser.hpp"

#include <algorithm>

ArgumentParser::ArgumentParser(int argc, char** argv) {
    argc_ = argc;
    argv_.reserve(argc_);
    for (int i = 0; i < argc_ ; ++i) {
        argv_.push_back(argv[i]);
    }
    appName_ = argv_[0];
}

std::string ArgumentParser::getInputDirectory() const {
    if (argc_ == 1) {
        return "";
    }
    return argv_[1]; 
}

std::string ArgumentParser::getOutputFileName() const {
    if (argc_ <= 2) {
        return "";
    }
    return argv_[2]; 
}

bool ArgumentParser::isHelpNeeded() const {
     return argc_ == 1 || argc_ > 3 || argumentExists("-h") || argumentExists("--help");
}

bool ArgumentParser::argumentExists(const std::string& option) const {
    return std::find(begin(argv_), end(argv_), option) != end(argv_);
}

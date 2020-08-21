#pragma once

#include <filesystem>
#include <string>

class Input {
public:
    Input(const std::string& directory) 
        : directoryPath_(std::filesystem::path(directory))
    {};

private:
    std::filesystem::path directoryPath_;
};

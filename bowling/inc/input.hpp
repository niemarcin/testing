#pragma once

#include <filesystem>
#include <string>

class Input {
public:
    Input(const std::string& directory); 

    bool isValid() const { return isValid_; }
private:
    std::filesystem::path directoryPath_;
    bool isValid_;
};

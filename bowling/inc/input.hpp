#pragma once

#include <experimental/filesystem>
#include <string>

class Input {
public:
    Input(const std::string& directory); 

    bool isValid() const { return isValid_; }
private:
    std::experimental::filesystem::path directoryPath_;
    bool isValid_;
};

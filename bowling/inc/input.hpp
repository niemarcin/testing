#pragma once

#include <experimental/filesystem>
#include <string>

class Input {
public:
    Input(const std::string& directory); 

    bool isValid() const { return isValid_; }
    size_t getLinesNum() const { return lanesNum_; }
private:
    std::experimental::filesystem::path directoryPath_;
    bool isValid_;
    size_t lanesNum_;
    std::vector<std::string> fileNames_;

    std::vector<std::string> getFileNames();
};

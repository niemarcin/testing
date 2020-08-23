#pragma once

#include <experimental/filesystem>
#include <string>

#include "lane.hpp"

class Input {
public:
    Input(const std::string& directory);

    bool isValid() const { return isValid_; }
    size_t getLinesNum() const { return lanes_.size(); }
    Lane getLane(size_t index);

private:
    std::experimental::filesystem::path directoryPath_;
    bool isValid_;
    std::vector<Lane> lanes_;

    std::vector<std::string> getFileNames();
    void readLanes(const std::vector<std::string>& fileNames);
};

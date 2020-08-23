#pragma once

#include <experimental/filesystem>
#include <memory>
#include <string>

#include "lane.hpp"

class Input {
public:
    Input(const std::string& directory);

    bool isValid() const { return isValid_; }
    size_t getLinesNum() const { return lanesNum_; }
    std::shared_ptr<Lane> getLane(size_t index);

private:
    std::experimental::filesystem::path directoryPath_;
    bool isValid_;
    std::vector<std::shared_ptr<Lane>> lanes_;
    size_t lanesNum_;

    std::vector<std::string> getFileNames();
    void readLanes(const std::vector<std::string>& fileNames);
    void readPlayers(const std::string& fileName, Lane& lane);
};

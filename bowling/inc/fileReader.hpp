#pragma once

#include <experimental/filesystem>
#include <memory>
#include <string>

#include "lane.hpp"

class FileReader {
public:
    FileReader(const std::string& directory);

    bool isValid() const { return isValid_; }
    size_t getLanesNum() const { return lanes_.size(); }
    std::shared_ptr<Lane> getLane(size_t index);

private:
    std::experimental::filesystem::path directoryPath_;
    bool isValid_;
    std::vector<std::shared_ptr<Lane>> lanes_;

    bool checkDirectory();
    std::vector<std::experimental::filesystem::path> makeFileList();
    void readFiles(const std::vector<std::experimental::filesystem::path>& files);
    void readPlayers(const std::experimental::filesystem::path& file, Lane& lane);
};

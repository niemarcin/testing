#pragma once

#include <experimental/filesystem>
#include <memory>
#include <string>

#include "lane.hpp"

namespace fs = std::experimental::filesystem;

class FilesReader {
public:
    FilesReader(const std::string& directory);

    bool isValid() const { return isValid_; }
    size_t getLanesNum() const { return lanes_.size(); }
    std::shared_ptr<Lane> getLane(size_t index) const;

private:
    fs::path directoryPath_;
    bool isValid_;
    std::vector<std::shared_ptr<Lane>> lanes_;

    bool checkDirectory() const;
    std::vector<std::experimental::filesystem::path> makeFileList();
    void readFiles(const std::vector<fs::path>& files);
    void readPlayers(const std::experimental::filesystem::path& file, Lane& lane);
};

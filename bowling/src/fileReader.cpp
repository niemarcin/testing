#include <algorithm>
#include <fstream>

#include "fileReader.hpp"

namespace fs = std::experimental::filesystem;

FileReader::FileReader(const std::string& directory) : directoryPath_(fs::path(directory)), isValid_(false) {
    if (!fs::exists(directoryPath_)) {
        return;
    }
    if (!fs::is_directory(directoryPath_)) {
        return;
    }
    std::vector<fs::path> files = makeFileList();
    readLanes(files);
    isValid_ = true;
};

std::vector<fs::path> FileReader::makeFileList() {
    std::vector<fs::path> files;

    for (const auto& entry : fs::directory_iterator(directoryPath_)) {
        auto filename = entry.path().filename();
        if (fs::is_regular_file(entry.status())) {
            files.push_back(entry.path());
        }
    }
    files.shrink_to_fit();
    std::sort(files.begin(), files.end());

    return files;
}

std::shared_ptr<Lane> FileReader::getLane(size_t index) {
    if (index < lanes_.size()) {
        return lanes_[index];
    }
    return nullptr;
}

void FileReader::readLanes(const std::vector<fs::path>& files) {
    for (const auto& file : files) {
        Lane lane(file.stem());
        readPlayers(file, lane);
        lanes_.push_back(std::make_shared<Lane>(lane));
    }
}

void FileReader::readPlayers(const fs::path& file, Lane& lane) {
    std::ifstream infile(file);
    std::string line;
    while (std::getline(infile, line)) {
        lane.addPlayer(line);
    }
}

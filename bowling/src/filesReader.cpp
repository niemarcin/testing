#include "filesReader.hpp"

#include <algorithm>
#include <fstream>
#include <stdexcept>

FilesReader::FilesReader(const std::string& directory) : directoryPath_(fs::path(directory)) {
    checkDirectory();

    readFiles(makeFileList());
};

void FilesReader::checkDirectory() const {
    if (!fs::exists(directoryPath_)) {
        throw std::invalid_argument("Directory does not exist");
    }
    if (!fs::is_directory(directoryPath_)) {
        throw std::invalid_argument("Not a directory");
    }
}

std::vector<fs::path> FilesReader::makeFileList() {
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

std::shared_ptr<Lane> FilesReader::getLane(size_t index) const {
    if (index < lanes_.size()) {
        return lanes_[index];
    }
    return nullptr;
}

void FilesReader::readFiles(const std::vector<fs::path>& files) {
    for (const auto& file : files) {
        Lane lane(file.stem());
        readPlayers(file, lane);
        lanes_.push_back(std::make_shared<Lane>(lane));
    }
}

void FilesReader::readPlayers(const fs::path& file, Lane& lane) {
    std::ifstream infile(file);
    std::string line;
    while (std::getline(infile, line)) {
        lane.addPlayer(line);
    }
}

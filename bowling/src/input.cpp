#include <algorithm>
#include <fstream>

#include "input.hpp"

namespace fs = std::experimental::filesystem;

Input::Input(const std::string& directory) : directoryPath_(fs::path(directory)), isValid_(false), lanes_({}) {
    if (!fs::exists(directoryPath_)) {
        return;
    }
    if (!fs::is_directory(directoryPath_)) {
        return;
    }
    std::vector<fs::path> files = getFiles();
    readLanes(files);
    lanesNum_ = lanes_.size();
    isValid_ = true;
};

std::vector<fs::path> Input::getFiles() {
    std::vector<fs::path> files{};

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

std::shared_ptr<Lane> Input::getLane(size_t index) {
    if (index < lanesNum_) {
        return lanes_[index];
    }
    return nullptr;
}

void Input::readLanes(const std::vector<fs::path>& files) {
    for (const auto& file : files) {
        std::string fileName = file.filename().c_str();
        size_t lastdot = fileName.find_last_of(".");
        std::string laneName;
        if (lastdot == std::string::npos) {
            laneName = fileName;
        } else {
            laneName = fileName.substr(0, lastdot);
        }
        Lane lane(laneName);
        readPlayers(file, lane);
        lanes_.emplace_back(std::make_shared<Lane>(lane));
    }
}

void Input::readPlayers(const fs::path& file, Lane& lane) {
    std::ifstream infile(file);
    std::string line;
    while (std::getline(infile, line)) {
        lane.addPlayer(line);
    }
}

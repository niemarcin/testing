#include <algorithm>
#include <fstream>

#include "input.hpp"

namespace fs = std::experimental::filesystem;

Input::Input(const std::string& directory) : directoryPath_(fs::path(directory)), isValid_(false) {
    if (!fs::exists(directoryPath_)) {
        return;
    }
    if (!fs::is_directory(directoryPath_)) {
        return;
    }
    std::vector<std::string> files = getFileNames();
    readLanes(files);
    lanesNum_ = lanes_.size();
    isValid_ = true;
};

std::vector<std::string> Input::getFileNames() {
    std::vector<std::string> files;

    for (const auto& entry : fs::directory_iterator(directoryPath_)) {
        auto filename = entry.path().filename();
        if (fs::is_regular_file(entry.status())) {
            files.push_back(filename.c_str());
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

void Input::readLanes(const std::vector<std::string>& fileNames) {
    for (const auto& file : fileNames) {
        size_t lastdot = file.find_last_of(".");
        std::string laneName;
        if (lastdot == std::string::npos) {
            laneName = file;
        } else {
            laneName = file.substr(0, lastdot);
        }
        Lane lane(laneName);
        readPlayers(file, lane);
        lanes_.emplace_back(std::make_shared<Lane>(lane));
    }
}

void Input::readPlayers(const std::string& fileName, Lane& lane) {
    std::ifstream infile(fileName);
    std::string line;

    while (std::getline(infile, line)) {
        lane.addPlayer(line);
    }
}

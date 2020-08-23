#include <input.hpp>

namespace fs = std::experimental::filesystem;

Input::Input(const std::string& directory)
    : directoryPath_(fs::path(directory))
    , isValid_(false)
    , lanesNum_(0)
{
    if (!fs::exists(directoryPath_)) {
        return;
    }
    if (!fs::is_directory(directoryPath_)) {
        return;
    }

    fileNames_ = getFileNames();

    /* ToDo: add more validation */

    isValid_ = true;
};

std::vector<std::string> Input::getFileNames()
{
    std::vector<std::string> files;

    for (const auto& entry : fs::directory_iterator(directoryPath_)) {
        auto filename = entry.path().filename();
        if (fs::is_regular_file(entry.status())) {
            files.push_back(filename.c_str());
        }
    }
    files.shrink_to_fit();
    lanesNum_ = files.size();

    return files;
}


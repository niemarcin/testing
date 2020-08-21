#include <input.hpp>

namespace fs = std::filesystem;

Input::Input(const std::string& directory)
    : directoryPath_(fs::path(directory))
    , isValid_(false)
{
    if (!fs::exists(directoryPath_)) {
        return;
    }
    if (!fs::is_directory(directoryPath_)) {
        return;
    }

    /* ToDo: add more validation */

    isValid_ = true;
};
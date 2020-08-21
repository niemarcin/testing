#pragma once

#include <string>
#include <vector>

class CmdArgumentsHandler {
private:
    int argc_;
    std::vector<std::string> argv_{};
    std::string appName_{};
    
public:
    CmdArgumentsHandler(int argc, char** argv);

    std::string getAppName() const { return appName_; }
    std::string getArgument(size_t argIndex) const { return argv_[argIndex]; }

    bool cmdOptionExists(const std::string& option) const;
    bool argumentEndsWith(size_t argIndex, std::string const &ending) const;
};

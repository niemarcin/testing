#pragma once

#include <string>
#include <vector>

class ArgumentParser {
private:
    int argc_;
    std::vector<std::string> argv_{};
    std::string appName_{};

    bool cmdOptionExists(const std::string& option) const;
    
public:
    ArgumentParser(int argc, char** argv);

    std::string getAppName() const { return appName_; }
    std::string getInputDirectory() const;
    std::string getOutputFileName() const;
    bool isHelpNeeded() const;
};

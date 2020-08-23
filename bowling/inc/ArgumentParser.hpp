#pragma once

#include <string>
#include <vector>

class ArgumentParser {
public:
    ArgumentParser(int argc, char** argv);

    std::string getAppName() const { return appName_; }
    std::string getInputDirectory() const;
    std::string getOutputFileName() const;
    bool isHelpNeeded() const;
    
private:
    int argc_;
    std::vector<std::string> argv_{};
    std::string appName_{};

    bool argumentExists(const std::string& option) const;
};

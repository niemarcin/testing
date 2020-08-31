#pragma once

#include <string>
#include <vector>

class Lane {
public:
    Lane(const std::string& name) : name_(name) {}

    size_t getPlayersNum() const { return players_.size(); }
    std::string getPlayer(size_t index) const { return players_.at(index); }
    std::string getName() const { return name_; }

    void addPlayer(const std::string& player) { players_.push_back(player); }

private:
    std::string name_;
    std::vector<std::string> players_;
};

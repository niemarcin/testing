#pragma once

#include <string>
#include <vector>

#include "player.hpp"

class Lane {
public:
    Lane(const std::string& name) : name_(name) {}

    size_t getPlayersNum() const { return players_.size(); }
    Player getPlayer(size_t index) { return players_[index]; }
    std::string getName() const { return name_; }

    void addPlayer(const Player& player) { players_.push_back(player); }

private:
    std::string name_;
    std::vector<Player> players_;
};

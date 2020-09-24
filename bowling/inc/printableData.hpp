#pragma once

#include <string>
#include <vector>

enum class Status { 
    NO_GAME, 
    IN_PROGRESS, 
    FINISHED 
};

struct Player {
    Player(std::string name_, size_t score_) : name(name_), score(score_){};

    std::string name;
    size_t score;
};

struct LaneStruct {
    LaneStruct(){};
    LaneStruct(std::string name_, Status status_) : name(name_), status(status_){};

    std::string name;
    Status status;
    std::vector<Player> players;
};
#pragma once

#include <array>
#include <string>

constexpr size_t MAX_FRAMES = 10;
constexpr size_t MAX_BONUS_BALLS = 2;

class Player {
public:
    Player();
    enum Result { strike, spare, miss };
    struct Frame {
        Result result;
        size_t pins;
    };
private:
    std::string name_;
    std::array<Frame, MAX_FRAMES> frames_;
    size_t framesNum_;
    size_t bonusBalls_[MAX_BONUS_BALLS];
    size_t bonusBallsNum_;
};

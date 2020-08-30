#pragma once

#include <iostream>

constexpr int MAX_PINS{10};
constexpr int MAX_FRAMES{10};
constexpr int MAX_ROLLS{21};
constexpr int MAX_FRAME_SCORE{MAX_PINS};

class Game {
public:
    void roll(int pins);
    int score();
    void reset();

private:
    int rolls[MAX_ROLLS]{};
    int currentRoll{};

    bool isSpare(int firstFrameThrow);
    bool isStrike(int firstFrameThrow);
    int nextTwoBallsForStrike(int firstFrameThrow);
    int nextBallForSpare(int firstFrameThrow);
    int twoBallsInFrame(int firstFrameThrow);
};

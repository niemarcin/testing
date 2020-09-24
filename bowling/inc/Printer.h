#pragma once

#include "printableData.hpp"
#include "printerStream.hpp"

#include <ostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>


class Printer{
public:
    Printer(PrinterStream * stream) : stream_(stream){};
    void print(std::vector<LaneStruct> lanes);

private:
    void printHeader(LaneStruct & lane);
    void print(std::string text);
    void print(size_t value);
    std::string parseStatus(const Status status);
    void printPlayers(LaneStruct & lane);
    void printPlayer(Player & player);

private:
    PrinterStream * stream_;
};

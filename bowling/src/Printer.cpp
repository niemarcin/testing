#include "Printer.h"


    void Printer::print(std::vector<LaneStruct> lanes) {
        for(auto & lane : lanes){
            printHeader(lane);
            printPlayers(lane);
        }
    }

    void Printer::printHeader(LaneStruct & lane){
        print("### " + lane.name + ": " + parseStatus(lane.status) + " ###\n");
    }

    void Printer::print(std::string text){
        stream_->print(text);
    }

    void Printer::print(size_t value){
        stream_->print(value);
    }

    std::string Printer::parseStatus(const Status status) {
        switch(status){
        case Status::NO_GAME:
            return "no game";

        case Status::IN_PROGRESS:
            return "game in progress";
        
        case Status::FINISHED:
            return "game finished";

        default:
            return "";
        }
    }

    void Printer::printPlayers(LaneStruct & lane){
        for(auto & player : lane.players){
            printPlayer(player);
            print("\n");
        }
    }

    void Printer::printPlayer(Player & player){
        if(!player.name.empty()) {
            print(player.name + " ");
        }
        print(player.score);
    }



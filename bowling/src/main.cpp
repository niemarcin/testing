#include <algorithm>
#include <iostream>
#include <numeric>
#include <string>

#include "argumentParser.hpp"
#include "consoleStream.hpp"
#include "filesReader.hpp"
#include "frameParser.hpp"
#include "game.hpp"
#include "printableData.hpp"
#include "printer.hpp"

void showHelp(std::string appName);

int main(int argc, char* argv[]) {
    ArgumentParser ap{static_cast<size_t>(argc), argv};

    if (ap.isHelpNeeded()) {
        showHelp(ap.getAppName());
        return 0;
    }

    auto inputDirectory = ap.getInputDirectory();
    auto outputFileName = ap.getOutputFileName();

    std::cout << "input dir: " << inputDirectory << "\n";
    std::cout << "output file: " << outputFileName << "\n";

    ConsoleStream consoleStr;
    Printer prnt(&consoleStr);
    std::vector<LaneStruct> lanes;

    FilesReader reader(inputDirectory);
    std::cout << "num of lanes: " << reader.getLanesNum() << '\n';
    Game game;
    for (size_t i = 0; i < reader.getLanesNum(); i++) {
        auto lane = reader.getLane(i);
        std::cout << "name: " << lane->getName() << '\n';
        LaneStruct printableLane(lane->getName(), Status::NO_GAME);
        std::cout << "\tplayers num: " << lane->getPlayersNum() << '\n';
        bool allSequencesComplete = true;
        for (size_t j = 0; j < lane->getPlayersNum(); j++) {
            std::cout << "\t\tplayer: " << lane->getPlayer(j) << '\n';
            allSequencesComplete &= FrameParser::isSequenceComplete(lane->getPlayer(j));
            auto parsed = FrameParser::parse(lane->getPlayer(j));
            std::cout << "\t\tparsed: " << parsed.first << "  :  ";  
                            //<< std::accumulate(parsed.second.begin(), parsed.second.end()-1, 0) <<"\n\t";
            for (const auto& el : parsed.second) {
                std::cout << el << ';';
                game.roll(el);
            }
            std::cout << "\n\t\tscore: " << game.score();
            printableLane.players.emplace_back(parsed.first, game.score());
            game.reset();
            std::cout << "\n\n";
        }
        if (allSequencesComplete && lane->getPlayersNum()) {
            printableLane.status = Status::FINISHED;
        } else if (lane->getPlayersNum() == 0) {
            printableLane.status = Status::NO_GAME;
        } else {
            printableLane.status = Status::IN_PROGRESS;
        }
        std::cout << "\tstatus: " << int(printableLane.status)<<"\n";
        lanes.push_back(printableLane);
    }
    std::cout << "lanes size: " << lanes.size() << "\n";
    prnt.print(lanes);
    std::cout << consoleStr.str();

    return 0;
}

void showHelp(std::string appName) {
    std::cout << "Bowling game application reads text files from given directory, "
              << "calculates the game results and optionally saves the results to text file.\n\n"
              << "Application usage:\t" << appName << " <inputDirectory> [outputTextFile] [-h, --help]\n\n"
              << "Arguments:\n"
              << "\tinputDirectory\t\tMANDATORY: input directory with .txt files containing game scores\n"
              << "\toutputTextFile\t\tOPTIONAL: output .txt file to save processed results\n\n"
              << "Options:\n"
              << "\t-h,--help\t\tShow this help message\n"
              << std::endl;
}

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

    FilesReader reader(inputDirectory);
    std::cout << "num of lanes: " << reader.getLanesNum() << '\n';
    for (size_t i = 0; i < reader.getLanesNum(); i++) {
        auto lane = reader.getLane(i);
        std::cout << "name: " << lane->getName() << '\n';
        std::cout << "\tplayers num: " << lane->getPlayersNum() << '\n';
        for (size_t j = 0; j < lane->getPlayersNum(); j++) {
            std::cout << "\t\tplayer: " << lane->getPlayer(j) << '\n';
            auto parsed = FrameParser::parse(lane->getPlayer(j));
            std::cout << "\t\tparsed: " << parsed.first << "  :  " ;//<< std::accumulate(parsed.second.begin(), parsed.second.end()-1, 0) <<"\n\t";
            Game game;
            for(const auto& el : parsed.second){
                std::cout << el <<';';
                game.roll(el);
            }
            std::cout <<"\n\t\tscore: " << game.score();
            game.reset();
            std::cout << "\n\n";
        }
    }

    // ConsoleStream consoleStr;
    // Printer prnt(&consoleStr);
    // std::vector<LaneStruct> lanes;
    // //wypełnić lanes
    // prnt.print(lanes);

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

#include <algorithm>
#include <iostream>
#include <string>

#include "ArgumentParser.hpp"
#include "game.hpp"

void showHelp(std::string appName);

int main(int argc, char* argv[]) {
    ArgumentParser ap{argc, argv};

    if (argc == 1 || argc > 3 || ap.cmdOptionExists("-h") || ap.cmdOptionExists("--help")) {
        showHelp(ap.getAppName());
        return 0;
    }

    std::string inputDirectory = ap.getArgument(1);
    std::string outputTextFile{};
    if (argc == 3) {
        outputTextFile = ap.getArgument(2);
    }

    std::cout << "input dir: " << inputDirectory << "\n";
    std::cout << "output file: " << outputTextFile << "\n";

    std::string extension{".txt"};
    if (!ap.argumentEndsWith(2, extension)) {
        std::cout << "output file should have .txt extension\n";
    }

    return 0;
}

void showHelp(std::string appName)
{
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

#include <algorithm>

#include "game.hpp"

bool cmdOptionExists(char** begin, char** end, const std::string& option);
void showHelp(std::string appName);

int main(int argc, char* argv[]) {
    std::string inputDirectory{};
    std::string outputTextFile{};

    if (argc == 1 || argc > 3 || cmdOptionExists(argv, argv + argc, "-h") || cmdOptionExists(argv, argv + argc, "--help")) {
        showHelp(argv[0]);
        return 0;
    }

    inputDirectory = argv[1];
    if (argc == 3) {
        outputTextFile = argv[2];
    }

    std::cout << "input dir: " << inputDirectory << "\n";
    std::cout << "output file: " << outputTextFile << "\n";

    return 0;
}

bool cmdOptionExists(char** begin, char** end, const std::string& option) {
    return std::find(begin, end, option) != end;
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

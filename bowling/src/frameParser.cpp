#include <algorithm>
#include <functional>

#include "frameParser.hpp"
#include "tokenizer.hpp"

const char FrameParser::StrikeSign = 'X';
const char FrameParser::MissSign = '-';
const char FrameParser::SpareSign = '/';

void FrameParser::parseToken(const char token, size_t& lastRollValue) {
    switch (token) {
    case FrameParser::StrikeSign:
        lastRollValue = 10;
        break;
    case FrameParser::SpareSign:
        lastRollValue = 10 - lastRollValue;
        break;
    case FrameParser::MissSign:
        lastRollValue = 0;
        break;
    default:
        lastRollValue = static_cast<size_t>(token - '0');
        break;
    }
}

parsedFrame FrameParser::parse(const std::string& line) {
    std::vector<size_t> parsed{};
    size_t lastRollValue{};

    auto name = Tokenizer::readName(line);
    auto sequence = Tokenizer::readSequence(line);

    std::for_each(sequence.cbegin(), sequence.cend(), [&lastRollValue, &parsed](const auto& el) {
        FrameParser::parseToken(el, lastRollValue);
        parsed.push_back(lastRollValue);
    });

    return std::pair(name, parsed);
}

bool FrameParser::isSequenceComplete(const std::string& line) {
    const std::string EndOfSequenceDelimiter = "||";

    size_t position = line.find(EndOfSequenceDelimiter);
    
    if (position == std::string::npos) { // jeżeli nie znalazł || to znaczy że dana linia/sekwencja nie jest kompletna
        return false;
    } else {
        auto lastToken = line.at(position - 1);
        if (lastToken == FrameParser::StrikeSign) {// jeżeli znalazł || i znak który poprzedza || to X czyli w ostatnim rzucie był strike
            return line.substr(position + 2).length() == 1; //to sprawdź czy za || jest jeden dodatkowy znak, jeśli tak to sekwencja kompletna
        }
        else if (lastToken == FrameParser::SpareSign) {// jeżeli znalazł || i znak który poprzedza || to / czyli w ostatnim rzucie był spare
            return line.substr(position + 2).length() == 2;//to sprawdź czy za || są dwa dodatkowe znaki, jeśli tak to sekwencja kompletna
        }
        else {
            return true; // jeśli znalazł || a przed || nie było X ani / to sekwencja zakończona
        }
    }
}

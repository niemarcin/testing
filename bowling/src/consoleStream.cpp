#include "consoleStream.hpp"

void ConsoleStream::print(std::string stream){
    stream_ << stream;
}

void ConsoleStream::print(size_t value){
    stream_ << value;
}

std::string ConsoleStream::str() const {
    return stream_.str();
}

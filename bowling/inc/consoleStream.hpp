#pragma once

#include <sstream>
#include <string>

#include "printerStream.hpp"

class ConsoleStream : public PrinterStream{
public:
    void print(std::string stream) override;
    void print(size_t value) override;
    std::string str() const ;

private:
    std::ostringstream stream_;
};

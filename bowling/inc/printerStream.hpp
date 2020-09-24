#pragma once

class PrinterStream{
public:
    virtual void print(std::string stream) = 0;
    virtual void print(size_t value) = 0;
};

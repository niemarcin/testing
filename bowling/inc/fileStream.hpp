#pragma once

#include "printerStream.hpp"

#include <string>
#include <fstream>

class FileStream : public PrinterStream{
public:
    FileStream(std::string filePath);
    ~FileStream();

    void print(std::string stream) override;
    void print(size_t value) override;

private:
    std::ofstream * file_;
};
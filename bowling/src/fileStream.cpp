#include "fileStream.hpp"

#include <stdexcept>

FileStream::FileStream(std::string filePath){
    if(filePath.empty())
        throw std::invalid_argument("Invalid filename");
    
    file_ = new std::ofstream;
    file_->open(filePath);
}

FileStream::~FileStream(){
    file_->close();
    delete file_;
}

void FileStream::print(std::string stream){
    *file_ << stream;
};

void FileStream::print(size_t value){
    *file_ << value;
}

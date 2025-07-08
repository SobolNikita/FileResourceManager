#include "./FileHandler.hpp"


FileHandler::FileHandler(const char* path, const char* mode)
    : file_(std::fopen(path, mode), [](FILE* f){ if(f) std::fclose(f);})
{
    if (!file_) throw std::runtime_error("Cannot open file");
}

size_t FileHandler::read(char* buffer, size_t count) {
    size_t n = std::fread(buffer, 1, count, file_.get());
    if (ferror(file_.get())) throw std::runtime_error("Read error");
    return n;
}

size_t FileHandler::write(const char* data, size_t count) {
    size_t n = std::fwrite(data, 1, count, file_.get());
    if (ferror(file_.get())) throw std::runtime_error("Write error");
    return n;
}

bool FileHandler::isOpen() const { return static_cast<bool>(file_); }
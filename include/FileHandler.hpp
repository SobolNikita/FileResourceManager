#include <cstdio>
#include <memory>
#include <stdexcept>


class FileHandler {
    std::unique_ptr<FILE, void(*)(FILE*)> file_;
public:
    FileHandler(const char* path, const char* mode);

    // Читает до count байт в buffer, возвращает реально прочитанное
    size_t read(char* buffer, size_t count);

    // Записывает до count байт из data, возвращает реально записанное
    size_t write(const char* data, size_t count);

    bool isOpen() const;
};
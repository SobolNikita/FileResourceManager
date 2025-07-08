#include <memory>

class MemoryBlock {
public:
    MemoryBlock(size_t size);

    char* get() const;
    size_t getSize() const;

private:
    size_t size_;
    std::unique_ptr<char[]> data_;
};
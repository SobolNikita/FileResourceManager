#include "./MemoryBlock.hpp"

MemoryBlock::MemoryBlock(size_t size)
      : size_(size),
        data_(new char[size])
    {
        
    }

char* MemoryBlock::get() const { return data_.get(); }
size_t MemoryBlock::getSize() const { return size_; }
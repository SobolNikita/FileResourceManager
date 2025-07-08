#include "FileHandler.hpp"
#include "MemoryBlock.hpp"
#include <iostream>

int main() {
    FileHandler fh("data.txt", "r+");
    if (!fh.isOpen()) return 1;

    MemoryBlock mb(128); 
    size_t n = fh.read(mb.get(), mb.getSize());
    std::cout << "Read " << n << " bytes:\n";
    std::cout.write(mb.get(), n);
    std::cout << '\n';
    return 0;
}
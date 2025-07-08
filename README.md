# FileResourceManager

**Используемое**:
- C++17
- CMake
- RAII (`std::unique_ptr` с пользовательскими делетерами)
- `FILE*` через `std::fopen/std::fclose`
- Динамические буферы

---

## Пример использования

```cpp
#include "FileHandler.hpp"
#include "MemoryBlock.hpp"
#include <iostream>

int main() {
    FileHandler fh("data.bin", "rb");
    if (!fh.isOpen()) return 1;

    MemoryBlock mb(128);
    size_t n = fh.read(mb.get(), mb.getSize());
    std::cout << "Прочитано байт: " << n << "\n";
    std::cout.write(mb.get(), n);
    return 0;
}
```

**Ожидаемый вывод** (если в `data.bin` лежит «Hello»):
```
Прочитано байт: 5
Hello
```

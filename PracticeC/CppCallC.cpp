#include <iostream>

extern "C" {
#include "CLang.h"
}

int main() {
    std::cout << "----- Cpp call c method -----";
    CallC();
}
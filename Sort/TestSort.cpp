#include <iostream>
#include "SortStrategyHeader.h"

//clang++  -o TestSort.so -I. TestSort.cpp QuickSort.cpp
int main(int argc, char* args[]) {                              
    int arrays[] = {100, 0, 12, 10, 7, 6, 0};
    sort(arrays, 0, 6);

    int length = 7;

    while (length-- > 0) {
        std::cout << arrays[length] << ',';
    }

    std::cout << '\n';

    return 0;
}
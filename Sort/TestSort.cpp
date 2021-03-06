#include <iostream>

#include "SortStrategyHeader.h"

using namespace std;

//clang++  -o TestSort.so -I. TestSort.cpp QuickSort.cpp
int main(int argc, char* args[]) {                              
    int arrays[] = {100, 0, 12, 10, 7, 6, 0};
    int length = sizeof(arrays) / sizeof(arrays[0]);

    cout << "Arrays length: " << length << endl;

    cout << "pre sort: \n";
    iteratorElement(arrays, length);
    sort(arrays, 0, length);
    cout << "after sort: \n";
    iteratorElement(arrays, length);

    return 0;
}


#include <iostream>
using namespace std;

// for solve duplicate symbols
inline void iteratorElement(int * arrays, int length) {
    cout << "length: " << length;
    while (length-- > 0) {
        cout << arrays[length] << ',';
    }
    cout << '\n';
}

inline void swapElement(int *array, int start, int end)
{
    int cache = array[start];
    array[start] = array[end];
    array[end] = cache;
}

void sort(int *array, int start, int end);
#include <iostream>

using namespace std;

int main() 
{
    int arrays[] = {100, 0, 12, 10, 7, 6, 0};
    int length = sizeof(arrays) / sizeof(arrays[0]);
    cout << "arrays sizeof: " << sizeof(arrays) << endl;
    cout << "arrays 0 sizeof: " << sizeof(arrays[0]) << endl;
    cout << "array length: " << sizeof(arrays) / sizeof(arrays[0]) << endl;

    return 0;
}
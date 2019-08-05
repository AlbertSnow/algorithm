#include <iostream>

extern "C"
{
    void CallCpp()
    {
        std::cout << "I'm out this place";
    }
}
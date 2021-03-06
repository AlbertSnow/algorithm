#include <iostream>
using namespace std;

bool duplicate(int numbers[], int length, int* duplication) {
    if (numbers == nullptr || length <= 0)
    {
        return false;
    }
    
    for (int i = 0; i < length; i++)
    {
        if (numbers[i] < 0 || numbers[i] > length - 1)      
        {
            return false;
        }
    }

        for (int i = 0; i < length; i++)
        {
            while (numbers[i] != i)
            {
                if (numbers[i] == numbers[numbers[i]])
                {
                    *duplication = numbers[i];
                    return true;
                }

                // swap numbers[i] and numbers[numbers[i]]
                int temp = numbers[i];
                numbers[i] = numbers[temp];
                numbers[temp] = temp;
            }
        }
        return false;
    }

 int main(){
    int mubers[] = {2, 3, 3, 1, 4};
    int test = -1;
    int *duplications = &test;
    bool result = duplicate(mubers, 5, duplications);
    // bool result = false;
    std::cout << "hello ";
    std::cout << result << *duplications;
    return 1;
}
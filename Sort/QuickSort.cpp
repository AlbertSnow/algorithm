#include <iostream>

using namespace std;

void swapElement(int *array, int start, int end)
{
    int cache = array[start];
    array[start] = array[end];
    array[end] = cache;
}

void quickSort(int *array, int start, int end)
{
    int originalStart = start;
    int originalEnd = end;

    cout << "originalStart " << originalStart << '\n';
    cout << "originalEnd " << originalEnd << '\n';

    if (array == NULL || start >= end)
    {
        return;
    }

    if (end - start == 1) {
        if (array[start] > array[end])
        {
            swapElement(array, start, end);
        }
        return;
    }

    bool compareRight = true;

    while (start < end)
    {

        cout << "start" << start << ",end" << end << "\n";
        if (array[start] > array[end])
        {
            swapElement(array, start, end);
            compareRight = !compareRight;
        }

        if (compareRight)
        {
            end--;
        }
        else
        {
            start++;
        }
    }

    if (compareRight)
    {
        end++;
    }
    else
    {
        start--;
    }



    quickSort(array, originalStart, start);
    quickSort(array, end , originalEnd);
}


int main(int argc, char* args[]) {                              
    int arrays[] = {100, 0, 12, 10, 7, 6, 0};
    quickSort(arrays, 0, 6);

    int length = 7;

    while (length-- > 0) {
        cout << arrays[length] << ',';
    }

    cout << '\n';

    return 0;
}
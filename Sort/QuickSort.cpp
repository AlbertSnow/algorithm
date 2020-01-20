#include <iostream>
#include "SortStrategyHeader.h"

using namespace std;

void swapElement(int *array, int start, int end)
{
    int cache = array[start];
    array[start] = array[end];
    array[end] = cache;
}


void sort(int *array, int start, int end)
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

    sort(array, originalStart, start);
    sort(array, end , originalEnd);
}
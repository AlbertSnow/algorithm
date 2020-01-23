#include <iostream>
#include "SortStrategyHeader.h"

void sort(int *array, int start, int end) {
    if (array == NULL || (end - start) < 1)
    {
        return;
    }

    if (start == end)
    {
        printf("arrive end point, start: " + start);
        return;
    }

    int middle = (end - start ) / 2 + start;

    sort(array, start, middle);
    sort(array, middle, end);
    
    mergeSort(array, start, (end - start ) / 2, end);
}

void mergeSort(int *array, int start, int middle, int end ) {



}
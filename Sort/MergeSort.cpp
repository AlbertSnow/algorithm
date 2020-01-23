#include <iostream>
#include "SortStrategyHeader.h"

void mergeSort(int *array, int l, int m, int r);

void sort(int *array, int start, int end) {
    if (array == NULL || (end - start) < 1)
    {
        return;
    }

    if (start == end)
    {
        return;
    }

    int middle = (end - start ) / 2 + start;

    sort(array, start, middle);
    sort(array, middle+1, end);
    
    mergeSort(array, start, middle, end);
}

void mergeSort(int *array, int l, int m, int r) {
    int i, j, k;

    int n1 = m - 1 + 1;
    int n2 = r-m;

    // create empty arrays
    int L[n1], R[n2]; 

    for ( i = 0; i < n1; i++)
    {
        L[i] = array[l+i];
    }

    for ( j = 0; j < n1; j++)
    {
        R[j] = array[m+1+j];
    }

    i = 0;
    j = 0;
    k = l;

    while (i<n1 && j<n2)   
    {
        if (L[i] <= R[j])
        {
            array[k] = L[i];
            i++;
        }
        else 
        {
            array[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) 
    {
        array[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) 
    {
        array[k] = R[j];
        j++;
        k++;
    }
}
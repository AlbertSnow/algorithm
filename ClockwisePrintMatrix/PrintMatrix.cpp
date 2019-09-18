#include <iostream>

int * getInputMatrix(int n) {
    int inputMatrix[n * n];
    for (int i = 0; i < n * n; i++)
    {
        inputMatrix[i] = i;
    }
}

void printMatrix(int * n, int length) {
    for (int i = 0; i < length; i++)
    {
        std::cout << n[i];
        // printf(n[i]);                                              
    }
    
}


int main() {
    int matrixLenght = 4;

    int* inputMatirx = getInputMatrix(matrixLenght);


    printMatrix(inputMatirx, matrixLenght);
    return 0;
}
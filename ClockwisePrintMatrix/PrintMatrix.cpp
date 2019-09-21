#include <iostream>

int * initMatrixData(int n, int* matrix) {
    int value = 1;

    for (int i = 0; i < n * n; i++)
    {
        matrix[i] = i + 1;
    }
    return matrix;
}

void printMatrix(int dimension, int * matrix) {
    for (int i = 0; i < dimension * dimension; i++)
    {
        std::cout << matrix[i] << " ";
        if (matrix[i] % dimension == 0)
        {
            std::cout << "\n";
        }
    }
}


void printOutline (int startNum, int dimension, int firstDimension) {
    int currentValue = startNum;

    if (dimension <= 1)
    {
        std::cout << "\n traverse is over";
        return;
    }
    
    std::cout << currentValue << " ";
    for (int i = 0; i < dimension - 1; i++)
    {
        currentValue += 1;
        std::cout << currentValue << "a ";
    }
    for (int i = 0; i < dimension - 1; i++)
    {
        currentValue += firstDimension;
        std::cout << currentValue << "b ";
    }
    for (int i = 0; i < dimension - 1; i++)
    {
        currentValue -= 1;
        std::cout << currentValue << "c ";
    }
    for (int i = 0; i < dimension - 2; i++)
    {
        currentValue -= firstDimension;
        std::cout << currentValue << "d ";
    }


    printOutline(currentValue + 1, dimension - 2, firstDimension);
}


int main() {
    int matrixDimension = 10;
    
    int inputMatrix[matrixDimension * matrixDimension];
    initMatrixData(matrixDimension, inputMatrix);
    printMatrix(matrixDimension, inputMatrix);


    std::cout << "\n Start print matrix from out to inner \n";
    printOutline (1, matrixDimension, matrixDimension);
    
    return 0;
}
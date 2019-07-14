#include <cstring>
#include <iostream>

bool hasPathCor(const char* matrix, int rows, int cols, int row,
    int col, const char* str, int& pathLength, bool* visited) 
{
    if (str[pathLength] == '\0')
    {
        return true;
    }

    int itemCoord = row * cols + col;

    bool hasPath = false;
    if (row >= 0 && row < rows && col >= 0 && col < cols
                &&  matrix[itemCoord] == str[pathLength]
                && !visited[row * cols + col])
    {
        ++pathLength;
   
    visited[itemCoord] = true;

    hasPath = hasPathCor(matrix, rows, cols, row, col-1,
                str, pathLength, visited) 
            || hasPathCor(matrix, rows, cols, row, col+1,
                str, pathLength, visited)
            || hasPathCor(matrix, rows, cols, row-1, col-1,
                str, pathLength, visited)
            || hasPathCor(matrix, rows, cols, row+1, col,
                str, pathLength, visited);
    if (!hasPath)
    {
        --pathLength;
        visited[itemCoord] = false;
    }
    }
    return hasPath;
}

bool hasPath(char* matrix, int rows, int cols, char* str)
{
    if (matrix == nullptr || rows < 1 || cols < 1 || str == nullptr)
    {
        return false;
    }
    
    bool* visited = new bool[rows * cols];
    memset(visited, 0, rows * cols);
    
    int pathLength = 0;

    for (int row = 0; row < rows; ++row) 
    {
        for(int col = 0; col < cols; ++col) 
        {
            if (hasPathCor(matrix, rows, cols, row, col, str,
                pathLength, visited))
            {
                return true;
            }
        }
    }

    delete[] visited;
    return false;
}

int main(void) {
    char matrix[] = {
        'a', 'b', 't', 'g',
        'c', 'f', 'c', 's',
        'j', 'd', 'e', 'h'
    };

    char testChar[] = "bfce";
    bool result = hasPath(matrix, 3, 4, testChar);
    std::cout << "The result is " << result;
}


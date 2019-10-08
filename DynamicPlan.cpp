#include <iostream>
#include <time.h>
#include "charUtils.h"

using namespace std;

int cacheProductAfterCutRope(int n) {
    if (n <= 0)
    {
        cout << "Params invalid";
        return 0;
    } else if (n <= 4) {
        return n;
    }

    int* maxResults = new int[n + 1];

    maxResults[0]  = 0;
    maxResults[1]  = 1;
    maxResults[2]  = 2;
    maxResults[3]  = 3;

    int max = 0;

    for (int i = 4; i<= n; ++i) {
        max = 0;

        for (int j = 1; j <= i/2; j++)
        {
            int maxResult = maxResults[j] * maxResults[i - j];
            if (max < maxResult)
            {
                max = maxResult;
            }

            maxResults[i] = max;
        }
    }

    max = maxResults[n];
    delete[] maxResults;

    return max;
}



int maxProductAfterCutRope(int n) {
    if (n <= 0)
    {
        cout << "Params invalid";
        return 0;
    } else if (n <= 4) {
        return n;
    }


    int i = 1;
    int maxValue = 5;
    while (i <= n / 2 ) {
        int result = maxProductAfterCutRope(i) * maxProductAfterCutRope(n - i);
        if (result > maxValue)
        {
            maxValue = result;
            cout << "---------- max value change ----------";
        }
        cout << "index: " << i << '\n' << ", this result value: " << result;
        i++;
    }    

    return maxValue;
}

// test command: clang++ DynamicPlan.cpp  charUtils.cpp -o roap  && ./roap 10
int main(int argc, char* args[]) {                              
    int n = stringToNumber(args[1]);

    time_t startTime, endTime;

    time(&startTime);                                                                                                                                                                            
    
    // int maxValue = maxProductAfterCutRope(n);
    int maxValue = cacheProductAfterCutRope(n);

    time(&endTime);
    cout << "cost time: " << (difftime(endTime, startTime)) << '\n';

    cout << "max result: " << maxValue << '\n';
    return 0;
}
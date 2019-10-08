#include <iostream>
#include "charUtils.h"

using namespace std;

int maxProductAfterCutRope(int n) {
    if (n <= 0)
    {
        cout << "Params invalid";
        return 0;
    } else if (n <= 4) {
        return n;
    }


    int i = 1;
    int maxValue = 0;
    while (i <= n / 2 ) {
        int result = maxProductAfterCutRope(i) * maxProductAfterCutRope(n - i);
        if (result > maxValue)
        {
            maxValue = result;
            cout << "change cut point " << i << ", maxValue: " << maxValue << '\n';
        }
        i++;
    }    

    return maxValue;
}

int main(int argc, char* args[]) {                              
    int n = stringToNumber(args[1]);                                                                                                                                                                            
    int maxValue = maxProductAfterCutRope(n);
    cout << "max result: " << maxValue << " \n";
    return 0;
}
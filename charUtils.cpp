#include <iostream>
#include "charUtils.h"
using namespace std;

int  stringToNumber(char chars[]) {
    int result = 0; 
    if (chars == NULL || chars[0] == '\n' || chars[0] == '-') {
        cout << "input invalid, Support only number";

        return 0;
    } 

    int digit = chars[0] - '0';                                                                                                                                                                                                                                                             
    int i = 1;
    while (chars[i] != '\0') {
        digit = (chars[i] - '0') + (digit * 10);
        cout << "digit " << digit << '\n';
        i++;

        if(i > 9) {
            throw invalid_argument("input argument length big than 9");
        }
    }

    return digit;
}

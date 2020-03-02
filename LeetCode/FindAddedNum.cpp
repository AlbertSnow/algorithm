#include <iostream>
#include <iterator>
#include <vector>

using namespace std;

class Solution
{
public:

    // cost 5min,  21
    vector<int> twoSum(vector<int> &nums, int target)
    {
        vector<int> result;
        if (nums.size <= 1)
        {
            return result;
        }

        vector<int>::iterator ptr;
        vector<int>::iterator ptr2;
        for (ptr = nums.begin(); ptr < nums.end() - 1; ptr++) 
        {
            cout << *ptr << " ";
            for (ptr2 = ptr + 1; ptr2 < nums.end; ptr2++)
            {
                if (*ptr + *ptr2 == target )
                {
                }
                
            }
            
        }



    }
};
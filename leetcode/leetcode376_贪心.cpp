#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) 
    {
        if (nums.size() < 2) return nums.size();
        static const int BEGIN = 0;
        static const int UP = 1;
        static const int DOWN = 2;
        int STATE = BEGIN;
        int len = 1;
        for (int i = 1; i < nums.size(); ++i)
        {
            switch(STATE)
            {
                case BEGIN:
                    if(nums[i-1] < nums[i])
                    {
                        STATE = UP;
                        ++len;
                    }
                    else if(nums[i-1] > nums[i])
                    {
                        STATE = DOWN;
                        ++len;
                    }
                    break;
                case UP:
                    if ( nums[i-1] > nums[i])
                    {
                        STATE = DOWN;
                        ++len;
                    }
                    break;
                case DOWN:
                    if ( nums[i-1] < nums[i])
                    {
                        STATE = UP;
                        ++len;
                    }
                    break;
            }
        }
        return len;  
    }
};
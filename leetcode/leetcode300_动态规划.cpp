#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
#include <string>
#include <time.h>
using namespace std;


// class Solution {
// public:
//     int lengthOfLIS(vector<int>& nums) 
//     {
//         if (nums.size() == 0) return 0;
//         vector<int> dp(nums.size(), 0);
//         dp[0] = 1;
//         int LIS = 1;
//         for(int i = 1; i < dp.size(); ++i)
//         {
//             dp[i] = 1;
//             for (int j = 0; j < i; ++j)
//             {
//                 if (nums[i] > nums[j] && dp[i] < dp[j] + 1) dp[i] = dp[j] + 1;
//             }
//             if (LIS < dp[i]) LIS = dp[i];
//         }
//         return LIS;
//     }
// };



class Solution {
public:
    int lengthOfLIS(vector<int>& nums) 
    {
        if (nums.size() == 0) return 0;
        vector<int> stack;
        stack.push_back(nums[0]);
        for (int i = 0; i < nums.size(); ++i)
        {
            if (nums[i] > stack.back()) stack.push_back(nums[i]);
            else
            {
                for (int j = 0; j < stack.size(); ++j)
                {
                    if (stack[j] >= nums[i])  
                    {
                        stack[j] = nums[i];  //仅仅是替换 一直替换到新序列的长度大于就序列长度
                        break;
                    }
                }
            }

        }
        return stack.size();
    }
};
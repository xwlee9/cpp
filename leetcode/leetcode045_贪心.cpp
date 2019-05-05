#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;


class Solution {
public:
    int jump(vector<int>& nums) 
    {
        if (nums.size() < 2) return 0;
        int jump = 1;
        int current_max_index = nums[0]; //当前可以达到的最大位置
        int pre_max_index = nums[0]; // 各个位置可以到达的最远位置
        for (int i = 0; i < nums.size(); ++i)
        {
            if (current_max_index < i)
            {
                ++jump;
                current_max_index = pre_max_index;
            }
            if (pre_max_index < nums[i] + i) pre_max_index = nums[i] + i;
        }
        return jump;
    }
};
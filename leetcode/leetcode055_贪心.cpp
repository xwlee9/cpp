#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) 
    {
        int jump = 0;  
        int max_index = nums[0];
        while (max_index >= jump) // 确保最大可以跳跃值 大于等于 第jump个位置
        {
            // if (max_index < jump) return false;  // 如果 
            max_index = max_index >= (jump + nums[jump]) ? max_index : (jump + nums[jump]);
            if (max_index >= nums.size()-1) return true;
            ++jump;
        }
        return false;
    }
};
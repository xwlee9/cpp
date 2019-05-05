#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
using namespace std;

// class Solution {
// public:
//     vector<vector<int> > subsets(vector<int>& nums)
//     {
//         vector <vector <int> > result;  // 存储最后的结果
//         vector <int> item;  // 回溯产生各个子集的数组
//         result.push_back(item);
//         generate(0, nums, item, result);
//         return result;
//     }
// private:
//     void generate (int i, vector<int>& nums, vector <int> &item, vector <vector <int> > &result)
//     {
//         if(i >= nums.size()) return;
//         item.push_back(nums[i]);
//         result.push_back(item);
//         generate(i+1, nums, item, result);  // 
//         item.pop_back();
//         generate(i+1, nums, item, result);  // 回溯法
//     }
// };



class Solution {
public:
    vector<vector<int> > subsets(vector<int>& nums)
    {
        vector <vector<int> > result;
        // int all_set = pow(2,nums.size());
        int all_set = 1 << nums.size();
        for (int i = 0; i < all_set; ++i)
        {
            vector<int> item;
            for (int j = 0; j < nums.size(); ++j)
            {
                if (i & (1 << j)) item.push_back(nums[j]);  // (ABC) ==> 每1位为分别代别ABC 分别和 000 001 010 ...与& 代别每种出现的可能
            } 
            result.push_back(item);
        }
        return result;
    }
};
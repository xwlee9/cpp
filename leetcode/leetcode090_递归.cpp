#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
#include <set>
using namespace std;

// 去重复  ===> 排序一下

class Solution {
public:
    vector<vector<int> > subsetsWithDup(vector<int>& nums) 
    {
        vector< vector<int> > result;
        vector<int> item;
        set< vector<int> > res_set;
        sort(nums.begin(), nums.end());
        result.push_back(item);
        generate(0, item, result, res_set, nums);
        return result;  
    }
private:
    void generate(int i, vector<int>& item, vector< vector<int> >& result, set< vector<int> >& res_set, vector<int>& nums)
    {
        if(i >= nums.size()) return;
        item.push_back(nums[i]);
        if (res_set.find(item) == res_set.end()) // res_set去重集合中找不到item 
        {
            result.push_back(item);
            res_set.insert(item);
        }
        generate(i+1, item, result, res_set, nums);
        item.pop_back();
        generate(i+1, item, result, res_set, nums);
    }
};
#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
#include <set>
using namespace std;


class Solution {
public:
    vector<vector<int> > combinationSum2(vector<int>& candidates, int target)
    {
        vector< vector<int> > result;
        vector<int> item;
        set< vector<int> > res_set;
        sort(candidates.begin(), candidates.end());
        generate(0, item, result, res_set, candidates, 0, target);
        return result;  
    }
private:
    void generate(int i, vector<int>& item, vector< vector<int> >& result, set< vector<int> >& res_set, vector<int>& nums, int sum, int target)
    {
        if(i >= nums.size() || sum > target) return;
        item.push_back(nums[i]);
        sum += nums[i];
        if (res_set.find(item) == res_set.end() && sum == target) // res_set去重集合中找不到item 
        {
            result.push_back(item);
            res_set.insert(item);
        }
        generate(i+1, item, result, res_set, nums, sum, target);
        sum -= nums[i];
        item.pop_back();
        generate(i+1, item, result, res_set, nums, sum, target);
    }
};
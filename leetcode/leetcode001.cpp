class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int ln;
        ln = nums.size();
        vector<int> res;
        for (int i = 0; i < ln; i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (nums[j]+nums[i] == target)
                {
                    res.push_back(j);
                    res.push_back(i);
                    break;
                }
            }
        }
        return res;
    }
};
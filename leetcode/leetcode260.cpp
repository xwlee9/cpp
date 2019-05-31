class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) 
    {
        vector<int> res;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n-1; ++i)
        {
            if (nums[i] ^ nums[i+1]) res.push_back(nums[i]);
            else ++i;
        }
        if (res.size() != 2) res.push_back(nums[n-1]);
        return res;
    }
};
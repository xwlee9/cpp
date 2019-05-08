class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) 
    {
        vector< vector<int> > result;
        if (nums.size() < 3)  return result;
        sort(nums.begin(), nums.end());
        if (nums.back() < 0 || nums.front() > 0) return result;
        for (int i = 0; i < nums.size()-2; ++i)
        {
            if (nums[i] > 0) break;
            if (i > 0 && nums[i] == nums[i-1])  continue; 
            int j = i + 1;
            int k = nums.size() - 1;
            while (j < k)
            {
                if (0 - nums[i] == nums[j] + nums[k])
                {
                    result.push_back({nums[i], nums[j], nums[k]});
                    while (j < k && nums[j] == nums[j+1]) ++j;
                    while (j < k && nums[k] == nums[k-1]) --k;
                    ++j;
                    --k;
                }
                else if (0 - nums[i] > nums[j] + nums[k])  ++j;
                else --k;
            }
        }
        return result;
    }
};
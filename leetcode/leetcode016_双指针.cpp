class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) 
    {
        if (nums.size() < 3) return NULL;
        int diff = abs(nums[0] + nums[1] + nums[2] - target);
        int close = nums[0] + nums[1] + nums[2];
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); ++i)
        {
            int j = i + 1;
            int k = nums.size() - 1;
            while (j < k)
            {
                int sum = nums[i] + nums[j] + nums[k];
                if (diff > abs(sum - target))
                {
                    diff = abs(sum - target);
                    close = sum;
                }
                // diff = min(diff, abs(sum - target));
                if(sum > target) --k;
                else ++j;
            }
        }
        return close;
    }
};
class Solution {
public:
    int removeDuplicates(vector<int>& nums) 
    {
        int k = 0;
        int count = 1;
        if (0 == nums.size()) return 0;
        for (int i = 1; i < nums.size(); ++i)
        {
            if (nums[k] == nums[i]) 
            {
                if (count >= 2) continue;
                count ++;
                nums[++k] = nums[i];
            }
            if (nums[k] < nums[i])
            {
                count = 1;
                nums[++k] = nums[i];
            }
        }
        return k + 1;
    }
};
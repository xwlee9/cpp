class Solution {
public:
    int findMin(vector<int>& nums) 
    {
        // int res = nums[0];
        // for (int i = 1; i < nums.size(); ++i)
        // {
        //     res = min(res, nums[i]);
        // }
        // return res;
        
        int left = 0;
        int right = nums.size() - 1;
        while (left < right)
        {
            int mid = (left + right) / 2;
            if (nums[mid] > nums[right]) left = mid + 1;
            else right = mid;
        }
        return nums[left];
    }
};
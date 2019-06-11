class Solution {
public:
    bool search(vector<int>& nums, int target) 
    {
        int i = 0;
        int j = nums.size()-1;
        while (i <= j)
        {
            int mid = (i + j) / 2;
            // cout << mid << i << j << endl;
            if (target == nums[mid]) return true;
            if (nums[i] < nums[mid]) // 左边升
            {
                if (target >= nums[i] && target <= nums[mid]) j = mid-1;
                else i = mid + 1;
            }
            else if (nums[j] > nums[mid]) // 右升序
            {
                if (target >= nums[mid] && target <= nums[j]) i = mid+1;
                else j = mid - 1;
            }
            else // nums[mid] == nums[i] 或 nums[mid] == nums[j] 移动i 
            {
                if (target == nums[i]) return true;
                i++;  
            }
        }
        return false;
    }
};
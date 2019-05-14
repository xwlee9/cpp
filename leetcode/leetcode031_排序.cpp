class Solution {
public:
    void nextPermutation(vector<int>& nums) 
    {
        if (nums.size() < 2) return;
        int i = nums.size() - 2;
        int j = nums.size() - 1;
        while (i >= 0 && nums[i + 1] <= nums[i]) --i;  
        if (i >= 0)  // 非全部倒序
        {
            while (nums[j] <= nums[i])  --j;  // i+1 ===> end 从大到小排序好的 只要找到第一个比nums[i]大的 交换即可
            swap(nums[j], nums[i]);
        }
        reverse(nums.begin() + i + 1, nums.end() );  // 反序 即从小到大排列
    }
};
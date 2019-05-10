class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        int res = 0;
        int n = nums.size();
        for (int i = 0; i < 32; ++i) 
        {
            int count = 0;
            for (auto num : nums) 
            {
                if (num & (1 << i))  ++count; // 统计1的个数
            }
            res += count * (n - count);
        }
        return res;
    }
};
class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) 
    {
        int max_val;
        int sum = 0;
        for(int i = 0; i < k; ++i) sum += nums[i];  
        int res = sum;
        for(int i = k; i< nums.size(); ++i)
            res = (sum += (nums[i]- nums[i-k])) > res ? sum : res;
        return res * 1.0 / k;       
    }
};
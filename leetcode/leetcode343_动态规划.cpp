class Solution {
public:
    int integerBreak(int n) 
    {
        vector<int> dp(n+1,0);
        dp[1] = 1;
        // dp[2] = 1;
        for (int i = 2; i <= n; ++i)
        {
            for (int j = 1; j < i; ++j)
            {
                dp[i] = max(dp[j]*(i-j),max((i-j) * j, dp[i]));
            }
        }
        return dp[n];
    }
};
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) 
    {
        if (obstacleGrid.empty()) return 1;
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        // cout << m << n << endl;
        vector<vector<long long>> dp(m, vector<long long>(n,1));
        for(int i = 0; i < m; ++i)
        {
            for(int j = 0; j < n; ++j)
            {
                if (obstacleGrid[i][j] == 1) 
                {
                    dp[i][j] = 0; 
                    continue;
                }
                if (i == 0 && j > 0) dp[i][j] = dp[i][j-1];
                else if (j == 0 && i > 0) dp[i][j] = dp[i-1][j];
                else if (i > 0 && j > 0) dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }
        return dp[m-1][n-1];
    }
};
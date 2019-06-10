class Solution {
public:
    int minDistance(string word1, string word2) 
    {
        int m = word1.size();
        int n = word2.size();
        vector<vector<int>> dp(m+1, vector<int>(n+1));
        for (int i = 0; i <= m; ++i) dp[i][0] = i;
        for (int i = 0; i <= n; ++i) dp[0][i] = i;
        for (int i = 1; i <= m; ++i)
        {
            for (int j = 1; j <= n; ++j)
            {
                if (word1[i-1] == word2[j-1]) dp[i][j] = dp[i-1][j-1];
                else 
                {
                    dp[i][j] = min(dp[i-1][j-1], min(dp[i-1][j],dp[i][j-1])) + 1;  // 左上对应改， 左为增， 下为删
                }
            }
        }
        return dp[m][n];
    }
};

/*

  h o r s e
r 0 1 2 3 4 5
o 1 1 2 2 3 4
s 2 2 1 2 3 4
  3 3 2 2 2 3  
 
 0-1   -1    -2   -2     -3
 r->h  o->o  ->r  s->s  ->e
 右下改 右下  右增  右下   右增
*/
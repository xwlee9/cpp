#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
#include <string>
#include <time.h>
using namespace std;

class Solution {
public:
    int minPathSum(vector<vector<int> >& grid) 
    {
        if (grid.size() == 0) return 0;
        int row = grid.size();
        int col = grid[0].size();
        vector<vector<int> > dp(row, vector<int> (col,0));
        dp[0][0] = grid[0][0];
        for (int i = 1; i < col; ++i) dp[0][i] = grid[0][i] + dp[0][i-1];
        for (int i = 1; i < row; ++i)
        {
            dp[i][0] = dp[i-1][0] + grid[i][0];
            for (int j = 1; j < col; ++j)
            {
                dp[i][j] = min(dp[i-1][j],dp[i][j-1]) + grid[i][j];
            }
        }
        return dp[row-1][col-1];
    }
};
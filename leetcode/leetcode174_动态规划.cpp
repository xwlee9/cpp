#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
#include <string>
#include <time.h>
using namespace std;


class Solution {
public:
    int calculateMinimumHP(vector<vector<int> >& dungeon) 
    {
        if (dungeon.size() == 0) return 0;
        int row = dungeon.size();
        int col = dungeon[0].size();
        vector<vector<int> > dp(row, vector<int> (col,0));
        dp[row-1][col-1] = max(1,1-dungeon[row-1][col-1]);  // 如果为正 只要保证到达最后一点时血量为1即可
        for(int i = col - 2; i >= 0; --i) dp[row-1][i] = max(1,dp[row-1][i+1] - dungeon[row-1][i]);
        for(int i = row - 2; i >= 0; --i) dp[i][col-1] = max(1,dp[i+1][col-1] - dungeon[i][col-1]);
        for(int i = row - 2; i >= 0; --i)
        {
            for(int j = col - 2; j >= 0; --j)
            {
                int dp_min = min(dp[i+1][j],dp[i][j+1]);
                dp[i][j] = max(1, dp_min -  dungeon[i][j]);
            }
        }
    return dp[0][0];
    }
};
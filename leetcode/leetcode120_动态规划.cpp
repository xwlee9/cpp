#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
#include <string>
#include <time.h>
using namespace std;

class Solution {
public:
    int minimumTotal(vector<vector<int> >& triangle) 
    {
        if (triangle.size() == 0) return 0;
        vector<vector<int> > dp;
        for (int i = 0; i < triangle.size(); ++i)
        {
            dp.push_back(vector<int>());
            for (int j = 0; j < triangle.size(); ++j)
            {
                dp[i].push_back(0);
            }
        }
        for (int i = 0; i < triangle.size(); ++i)
        {
            dp[dp.size()-1][i] = triangle[dp.size()-1][i];
        }
        for (int i = dp.size() -2; i >= 0; --i)
        {
            for (int j = 0; j < triangle[i].size(); ++j)
            {
                dp[i][j] = min(dp[i+1][j], dp[i+1][j+1]) + triangle[i][j];
            }
        }
        return dp[0][0];        
    }
};
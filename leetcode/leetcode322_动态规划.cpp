#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;


class Solution {
public:
    int coinChange(vector<int>& coins, int amount) 
    {
        vector<int> dp;
        for (int i = 0; i <= amount; ++i)
        {
            dp.push_back(-1);  // 所有金额最优解均为-1
        }
        dp[0] = 0;  // 金额0 最优解为0
        for (int i = 0; i <= amount; ++i) // 循环各个面值 找到dp[i] 最优解
        {
            for (int j = 0; j < coins.size(); ++j)  // 
            {
                if (i-coins[j] >= 0 && dp[i-coins[j]] != -1)  // 如果上一个可以到达
                {
                    if (dp[i] == -1 || dp[i] > dp[i-coins[j]] + 1)  // 如果dp[i] 更小 更新dp[i] 
                    {
                        dp[i] = dp[i-coins[j]] + 1;
                    }
                }
            }
        }
        return dp[amount];
    }
};
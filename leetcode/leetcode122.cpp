class Solution {
public:
    int maxProfit(vector<int>& prices) 
    {
        if (prices.empty()) return 0;
        int res = 0;
        int m = prices[0];
        for (int i = 1; i < prices.size(); ++i)
        {
            if (prices[i] < prices[i-1]) 
            {
                res += prices[i-1] - m;
                m = prices[i];
            }
        }
        return res+prices[prices.size()-1]-m;
    }
};
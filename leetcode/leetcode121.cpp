class Solution {
public:
    int maxProfit(vector<int>& prices) 
    {
        if (prices.empty()) return 0;
        int m = prices[0];
        int n = m;
        int res = 0;
        for (int i = 1; i < prices.size(); ++i)
        {
            m = max(prices[i], m);
            if (prices[i] < n) 
            {
                n = prices[i];
                m = prices[i];
            }
            res = max (res, m - n);
        }
        return res;
    }
};
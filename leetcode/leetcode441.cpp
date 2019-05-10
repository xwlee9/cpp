class Solution {
public:
    int arrangeCoins(int n) 
    {
        int i = 0;
        long long sum = 0;
        while(sum <= n) 
        {
            ++i;
            sum += i;
        }
        // if (sum == n) return i;
        return (i-1);
    }
};
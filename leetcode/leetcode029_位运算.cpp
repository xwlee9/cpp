class Solution {
public:
    int divide(int dividend, int divisor) 
    {
        long long m = abs((long long)dividend);
        long long n = abs((long long)divisor);
        long long res = 0;
        if (m < n) return 0;
        while (m >= n)
        {
            long long temp = n;
            int count = 1;
            while (m > (temp << 1))
            {
                temp <<= 1;
                count <<= 1;
            }
            res += count;
            m -= temp;
        }
        if ((dividend > 0) ^ (divisor > 0)) res = -res;
        return res > INT_MAX ? INT_MAX : res;
    }
};
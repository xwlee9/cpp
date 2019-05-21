class Solution {
public:
    int mySqrt(int x) 
    {
        // long long i = 0;
        // while (i * i <= x) i++;
        // return i-1;
        if (x == 0) return 0;
        double res = 1;
        double last = 0;
        while (abs (res-last) > 0.1)
        {
            last = res;
            res = (res + x / res) / 2;
        }
        return (int)res;
    }
};
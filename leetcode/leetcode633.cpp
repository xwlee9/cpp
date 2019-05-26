class Solution {
public:
    bool judgeSquareSum(int c) 
    {
        if (c < 0) return false;
        int a = 0;
        int b = sqrt(c);
        while (a <= b)
        { 
            if ((long long)a * a + b * b > INT_MAX) 
            {
                --b;
                continue;
            };
            int sum = a * a + b * b;
            if (sum == c) return true;
            if (sum < c) ++a;
            else if (sum > c) --b;
        }
        return false;
    }
};
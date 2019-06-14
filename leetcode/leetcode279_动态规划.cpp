class Solution {
public:
    int numSquares(int n) 
    {
        // vector<int> dp(n+1,0);
        // for (int i = 1; i <= n; ++i)
        // {
        //     int val = i;
        //     for (int j = 1; j * j <= i; ++j)  val = min(val,dp[i-j*j]);
        //     dp[i] = val + 1;
        // }
        // return dp[n];
/*
Lagrange 四平方定理： 任何一个正整数都可以表示成不超过四个整数的平方之和。
满足四数平方和定理的数n，必定满足 n = 4^a (8b + 7)  ==> 此处为4个数
*/
        if (n == 0) return 0;
        int m = n;
        while (m % 4 == 0)  m = m / 4;
        if (m % 8 == 7) return 4;
        int a = sqrt(n);
        if (a * a == n) return 1;
        for (int i = 1; i*i < n; ++i)
        {
            int temp = i * i;
            int b = sqrt(n-temp);
            if (n-temp == b*b) return 2;
        }
        return 3;
    }
};
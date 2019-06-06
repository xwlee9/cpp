class Solution {
public:
    int countPrimes(int n) 
    {
        vector<bool> prim(n, true);  // 全部设置成是质数 true
        int count = 0;
        for (int i = 2; i < n; ++i)
        {
            if (prim[i])
            {
                count ++;
                for (int j = 2; j * i < n; ++j) prim[j * i] = false;  // 设置为非质数
            }
        }
        return count;
    }
};
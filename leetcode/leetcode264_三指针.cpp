class Solution {
public:
    int nthUglyNumber(int n) 
    {
        vector<int> res(1, 1);
        int i = 0;
        int j = 0;
        int k = 0;
        while (--n)
        {
            int temp = min(res[i]*2, res[j]*3);
            temp = min(temp, res[k]*5);
            res.push_back(temp);
            if (res[i]*2 == temp) ++i;
            if (res[j]*3 == temp) ++j;
            if (res[k]*5 == temp) ++k;
        }
        return res.back();
    }
};
// class Solution {
// public:
    // string getPermutation(int n, int k) 
    // {
    //     string res;
    //     string temp;
    //     map<int, int> m;
    //     int count = 0;
    //     fun(0, n, k, count, temp, res, m);
    //     return res;
    // }
    // void fun(int i, int n, int k, int &count, string& temp, string& res,  map<int, int>& m)
    // {
    //     // if (count == k) return;
    //     if (i == n) 
    //     {
    //         count ++;
    //         if (count == k) res = temp;
    //         return;
    //     }
    //     string num = "123456789";
    //     for (int j = 0; j < n; ++j)
    //     {
    //         if (m[j] == 0)
    //         {
    //             temp += num[j];
    //             m[j] = 1;
    //             fun(i + 1, n, k, count, temp, res, m);
    //             if (count == k) return;
    //             temp.erase(temp.end()-1);
    //             m[j] = 0;
    //         }
    //     }
    // }
// };

class Solution {
public:
    string getPermutation(int n, int k) 
    {
        string res;
        string num = "123456789";
        int m = 1;
        --k;
        for (int i = n-1; i > 0; --i) m = m*i;
        for (int i = n; i > 0; --i)
        {
            int temp = k / m;
            k = k % m;
            if (i > 2) m = m / (i - 1);
            else m = 1;
            res += num[temp];
            num.erase(temp, 1);
        } 
        return res;
    }      
};
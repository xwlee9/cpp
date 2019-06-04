class Solution {
public:
    vector<vector<int>> combine(int n, int k) 
    {
        vector<int> temp;
        map<int, int> mp;
        vector<vector<int>> res;
        int count = 0;
        fun(1,n,k,count,temp,res,mp);
        return res;
    }
    void fun(int level, int n, int k, int& count, vector<int>& temp, vector<vector<int>>& res, map<int, int>& mp)
    {
        if (count == k)
            {
                res.push_back(temp);
            }
        for (int i = level; i <= n; ++i)
        {
            if (mp[i] == 1) continue;
            temp.push_back(i);
            mp[i] = 1;
            count ++;
            fun(i,n,k,count,temp,res,mp);
            temp.pop_back();
            mp[i] = 0;
            count --;
        }
    }
};
class Solution {
public:
    vector<vector<int>> generate(int numRows) 
    {
        if (numRows == 0) return {};
        vector<vector<int>> res(1,{1});
        for (int i = 1; i < numRows; ++i)
        {
            res.push_back({});
            for (int j = 0; j <= i; ++j)
            {
                if (j == 0) res[i].push_back(res[i-1][j]);
                else if (j == i) res[i].push_back(res[i-1][j-1]);
                else res[i].push_back(res[i-1][j-1] + res[i-1][j]);
            }
        }
        return res;
    }
};
class Solution {
public:
    vector<int> getRow(int rowIndex) 
    {
        // if (rowIndex == 0) return {};
        vector<int> res(1,1);
        for (int i = 1; i <= rowIndex; ++i)
        {
            vector<int> temp;
            for (int j = 0; j <= i; ++j)
            {
                if (j == 0) temp.push_back(res[j]);
                else if (j == i) temp.push_back(res[j-1]);
                else temp.push_back(res[j-1] + res[j]);
            }
            res = temp;
        }
        return res;           
    }
};
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) 
    {
        if(matrix.empty()) return;
        bool flag1 = false; 
        bool flag2 = false;
        int m = matrix.size();
        int n = matrix[0].size();
        for (int i = 0; i < m; ++i)
        {
            if (matrix[i][0] == 0) flag1 = true;  // 如果第一列中存在0，flag1为true
        }
        for (int i = 0; i < n; ++i)
        {
            if (matrix[0][i] == 0) flag2 = true;   // 如果第一行中存在0，flag2为true
        }
        for(int i = 1; i < m; ++i)
        {
            for (int j = 1; j < n; ++j)
            {
                if (matrix[i][j] == 0)
                {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }
        for(int i = 1; i < m; ++i)
        {
            for (int j = 1; j < n; ++j)
            {
                if (matrix[0][j] == 0 || matrix[i][0] == 0) matrix[i][j] = 0;
            }
        }
        // cout << flag2 << endl;
        if (flag1) 
        {
            for(int i = 0; i < m; ++i) matrix[i][0] = 0;
        }
        if (flag2) 
        {
            for(int i = 0; i < n; ++i) matrix[0][i] = 0;
        }
    }
};
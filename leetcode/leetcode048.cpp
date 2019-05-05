class Solution {
public:
    void rotate(vector<vector<int>>& matrix) 
    {
        int temp = 0;
        // vector<int> reverse;
        int n = matrix.size();
        if (n < 2) return;
        // reverse = matrix[n - 1]
        for (int i = 0; i < n / 2; ++i)
        {
            vector<int> temp1 = matrix[n-1-i]; 
            matrix[n-1-i] = matrix[i];
            matrix[i] = temp1;
        }
        
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < i ;++j)
            {
                temp = matrix[i][j];
                matrix[i][j] = matrix[j][i];
                matrix[j][i] = temp;
            }
        }        
    }
};
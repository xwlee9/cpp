class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) 
    {
        if (matrix.size() == 0 || matrix[0].size() == 0 || target < matrix[0][0]) return false;
        if (target == matrix[0][0]) return true;
        int row = matrix.size()-1;
        int col = 0;
        while (row >= 0 && col < matrix[0].size())
        {
            if (target > matrix[row][col])  col ++;
            else if (target < matrix[row][col]) row --;
            else return true;
        }
        return false;
    }
};
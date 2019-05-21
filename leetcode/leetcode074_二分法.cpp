class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) 
    {
        if (matrix.size() == 0 || matrix[0].size() == 0 || target < matrix[0][0]) return false;
        // if (target == matrix[0][0]) return true;
        int row = matrix.size();
        int col = matrix[0].size();
        int rh = row-1;
        int rl = 0;
        int ch = col-1;
        int cl = 0;
        while (rh >= rl)
        {
            int mid = (rh + rl) / 2;
            if (target < matrix[mid][0])  rh = mid -1;
            else if (target > matrix[mid][0]) rl = mid + 1;
            else return true;
        }
        rl -= 1;
        while (ch >= cl)
        {
            int mid = (ch + cl) / 2;
            if (target < matrix[rl][mid])  ch = mid - 1;
            else if (target > matrix[rl][mid]) cl = mid + 1;
            else return true;
        }
        return false;
    }
};
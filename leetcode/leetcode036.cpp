class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) 
    {
        if (board.empty() || board[0].empty()) return false;
        int m = board.size();
        int n = board[0].size();        
        vector<vector<bool> > row(m, vector<bool>(n, false));
        vector<vector<bool> > col(m, vector<bool>(n, false));
        vector<vector<bool> > cell(m, vector<bool>(n, false));
        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (board[i][j] >= '1' && board[i][j] <= '9')
                {
                    int temp = board[i][j] - '1';
                    // row 记录每一行出现的数字 col 记录每一列出现的数字 cell 记录每个方块出现数字===>转成行记录 如果出现 为true 
                    if (row[i][temp] || col[temp][j] || cell[3*(i/3) + j/3][temp]) return false;
                    row[i][temp] = true;
                    col[temp][j] = true;
                    cell[3*(i/3) + j/3][temp] = true;
                }
                
            }
        }
        return true;
    }
};
class Solution {
public:
    void solveSudoku(vector<vector<char> >& board) 
    {
        if (board.empty() || board.size() != 9 || board[0].size() != 9) return;
        solveSudokuDFS(board, 0, 0);
    }
private:
    bool solveSudokuDFS(vector<vector<char> >& board, int i, int j)
    {
        if (i == 9) return true;
        if (j == 9) return solveSudokuDFS(board, i+1, 0);
        if (board[i][j] == '.')
        {
            for(int k = 1; k <= 9; ++k)
            {
                board[i][j] = (char)('0' + k);
                if (is_valid(board, i, j))
                {
                    if(solveSudokuDFS(board, i, j+1)) return true;
                }
                board[i][j] = '.';  
            }
        }
        else return solveSudokuDFS(board,i, j+1);
        return false;
    }
    bool is_valid(vector<vector<char> >& board, int i, int j)
    {
        for(int col = 0; col < 9; ++col)  // 行查找
        {
            if(col != j && board[i][j] == board[i][col]) return false;
        }
        for (int row = 0; row < 9; ++row)   //列查找
        {
            if (row != i && board[i][j] == board[row][j]) return false;
        }
        for (int row = i / 3 * 3; row < i / 3 * 3 + 3; ++row)   // block查找
        {
            for (int col = j / 3 * 3; col < j / 3 * 3 + 3; ++col) 
            {
                if ((row != i || col != j) && board[i][j] == board[row][col]) return false;
            }
        }
        return true;
    }
};
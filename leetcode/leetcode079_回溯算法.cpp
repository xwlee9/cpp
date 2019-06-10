class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) 
    {
        if (board.empty()) return false;
        int m = board.size();
        int n = board[0].size();
        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (search(board, word, i, j , m, n, 0)) return true;
                // cout << i << endl;
            }
        }
        return false;
    }
private:
    bool search(vector<vector<char>>& board, string word, int i, int j, int m, int n, int k)
    {
        if (k == word.size()) return true;  // 达到word长度
        if (i < 0 || j < 0 || i >= m || j >= n || word[k] != board[i][j]) return false;
        char t = board[i][j];
        board[i][j] = '*';
        bool res = search(board, word, i-1, j, m, n, k+1) || search(board, word, i, j-1, m, n, k+1) || search(board, word, i+1, j, m, n, k+1) || search(board, word, i, j+1, m, n, k+1);
        board[i][j] = t;
        return res;
    }
};
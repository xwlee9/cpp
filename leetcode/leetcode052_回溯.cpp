class Solution {
public:
    int totalNQueens(int n) 
    {
        int res = 0;
		std::vector<vector<int>> mark;
		for (int i = 0; i < n; ++i)
		{
			mark.push_back(vector<int>());
			for(int j = 0; j < n; ++j) mark[i].push_back(0);
		}
        generate(0, n, res, mark);
        return res;
	}
private:
	void generate(int k, int n, int& res, vector<vector<int>>& mark)
	{
		if (k == n)
		{
			res++;
			return;
		}
        for (int i = 0; i < n; ++i)
        {
            
            if (mark[k][i] == 0)
            {
                std::vector<std::vector<int>> temp = mark;
                put_down_the_queen(k, i, mark);
                generate(k+1, n, res, mark);
                mark = temp;
            }
        }
		
	}
	void put_down_the_queen (int x, int y, vector<vector<int>>& mark)
	{
		static const int dx[] = {-1, 1, 0, 0, -1, -1, 1, 1};
		static const int dy[] = {0, 0 , 1, -1, -1, 1, -1, 1};
		mark[x][y] = 1;
		for(int i = 0; i < mark.size(); ++i)
		{
			for(int j = 0; j < 8; ++j)
			{
				int new_x = x + i*dx[j];
				int new_y = y + i*dy[j];
				if (new_x >= 0 && new_x < mark.size() && new_y >= 0 && new_y < mark.size())mark[new_x][new_y] = 1;
			}
		}
	}
};
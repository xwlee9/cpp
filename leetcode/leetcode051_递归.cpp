#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
#include <string>
using namespace std;

class Solution {
public:
    vector<vector<string> > solveNQueens(int n) 
    {
        vector<vector<string> > result;
        vector<vector<int> > mark;  // 标记是否可以放置皇后
        vector<string> location;  // 存储摆放的结果 完成一次递归后的结果
        for (int i = 0; i < n; ++i)
        {
            mark.push_back( (vector<int>()) ); // 初始化行
            for (int j = 0; j < n; ++j) mark[i].push_back(0); // 初始化mark
            location.push_back("");
            location[i].append(n, '.');  // 每个加n个'.'
        }
        generate(0, n, location, mark, result);
        return result;
    }
private:
    void generate(int k, int n, vector<string>& location, vector< vector<int> >& mark, vector<vector<string> >& result)
    {
        if (k == n)
        {
            result.push_back(location);
            return;
        }
        for (int i = 0; i < n; ++i)
        {
            if (mark[k][i] == 0)
            {
                vector<vector<int> > temp = mark;
                location[k][i] = 'Q';  // 此位置放皇后
                put_down_the_queen(k,i,mark);  // 记录之前的mark状态
                generate(k + 1, n, location, mark, result);  // 如果可行的话 一直递归下去 知道return 否则 往下执行
                mark = temp;  // 回溯之前的状态
                location[k][i] = '.';  // 将皇后的点放置为'.'
            }
        }
    }
    void put_down_the_queen(int x, int y, vector< vector<int> >& mark)
    {
        static const int dx[] = {-1, 1, 0, 0, -1, -1, 1, 1};
        static const int dy[] = {0, 0, -1, 1, -1, 1, -1, 1};  // 方向数组
        mark[x][y] = 1;
        for (int i = 1; i < mark.size(); ++i)
        {
            for (int j = 0; j < 8; ++j)  // 8个方向
            {
                int new_x = x + i*dx[j];
                int new_y = y + i*dy[j];
                // new_x new_y 在区间[0,n)内
                if (new_x >= 0 && new_x < mark.size() && new_y >= 0 && new_y < mark.size()) mark[new_x][new_y] = 1;
            }
        }
    }
};


// void put_down_the_queen(int x, int y, vector< vector<int> > mark)
// {
//     static const int dx[] = {-1, 1, 0, 0, -1, -1, 1, 1};
//     static const int dy[] = {0, 0, -1, 1, -1, 1, -1, 1};  // 方向数组
//     mark[x][y] = 1;
//     for (int i = 1; i < mark.size(); ++i)
//     {
//         for (int j = 0; j < 8; ++j)  // 8个方向
//         {
//             int new_x = x + i*dx[j];
//             int new_y = y + i*dy[j];
//             // new_x new_y 在区间[0,n)内
//             if (new_x >= 0 && new_x < mark.size() && new_y >= 0 && new_y < mark.size()) mark[new_x][new_y] = 1;
//         }
//     }
// }
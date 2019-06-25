#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

bool cmp(const vector<int> &a, const vector<int> &b)
{
    return a[0] < b[0];
}
class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int> >& stations) 
    {
        priority_queue<int> Q; // 最大堆记录沿途加油量
        int result = 0;
        int distance = 0;
        // 插入终点
        vector<int> temp_target;
        temp_target.push_back(target);
        temp_target.push_back(0);
        stations.push_back(temp_target);  

        sort(stations.begin(), stations.end(),cmp); // 将距离起点从小到大排序 可以不用排序
        for (int i = 0; i < stations.size(); ++i)
        {
            int diff_dis = stations[i][0] - distance;  // 计算两点直接的距离
            distance = stations[i][0];  // 记录第i点距离起点的位置
            startFuel = startFuel - diff_dis; //消耗的油量
            while (!Q.empty() && startFuel < 0)
            {
                startFuel += Q.top();
                Q.pop();
                result++;
            }
            if (startFuel < 0 && Q.empty()) return -1;
            distance = stations[i][0];
            Q.push(stations[i][1]);
        }
        return result;
    }
};
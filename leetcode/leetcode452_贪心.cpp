#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool cmp (const vector<int> &a, const vector<int> &b)
{
    return a[0] < b[0];
}
class Solution {
public:
    int findMinArrowShots(vector<vector<int> >& points) 
    {
        if (points.size() == 0) return 0;
        sort(points.begin(), points.end(), cmp);
        int shoot_num = 1;
        int shoot_begin = points[0][0];
        int shoot_end = points[0][1];
        for(int i = 1; i < points.size(); ++i)
        {
            if(shoot_end >= points[i][0])   // shoot end 大于开始点 满足 
            {
                // shoot_begin = points[i][0]; 
                if(shoot_end > points[i][1]) shoot_end = points[i][1]; // 如果 shoot end 大于某点的截止 更新
            }
            else  // 否则 更新新的区间
            {
                ++shoot_num;
                // shoot_begin = points[i][0];
                shoot_end = points[i][1];
            }
        }  
        return shoot_num;
    }
};
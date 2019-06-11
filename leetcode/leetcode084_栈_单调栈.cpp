class Solution {
public:
    int largestRectangleArea(vector<int>& heights) 
    {
        int res = 0;
        stack<int> s;
        heights.push_back(0);
        for (int i = 0; i < heights.size(); ++i)
        {
            while (!s.empty() && heights[s.top()] >= heights[i])
            {
                int cur = s.top();
                cout << cur << endl;
                s.pop();
                res = max(res, heights[cur] * (s.empty() ? i : (i - s.top() - 1)));
            }  // 当heights[i]为最小的时候 s为空 
            s.push(i);
        }
        return res;
    }
};
/*

[0,1,1,2,1,0,1,3,1,2]
 0 1 2 3 4 5 6 7 8 9
 
cur ==> [1,3,2,4,0,7,6,9,8,5]
i = 2 top = 1  ==>   0 1 
i = 4 top = 3  ==>   1 1 ==> top = 2 ==> 

*/
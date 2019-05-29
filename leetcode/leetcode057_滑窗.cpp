class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) 
    {
        int i = 0;
        vector<vector<int>> res;
        while(i < intervals.size())
        {
            // cout << i << endl;
            if (newInterval[0] <= intervals[i][0]) 
            {
                if (newInterval[1] < intervals[i][0])
                {
                    res.push_back(newInterval);
                    swap(newInterval,intervals[i]);
                }
                else if (newInterval[1] <= intervals[i][1])
                {
                    newInterval[1] = intervals[i][1];
                }
                ++i;
            }
            else if (newInterval[0] <= intervals[i][1]) newInterval[0] = intervals[i][0];
            else //  if (newInterval[0] > intervals[i][1])
            {
                res.push_back(intervals[i]);
                ++i;
            }
        }
        res.push_back(newInterval);  
        return res;   
    }
};
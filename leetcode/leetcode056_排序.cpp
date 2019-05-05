class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) 
    {
        
        vector<vector<int>> result;
        vector<int> temp;
        sort (intervals.begin(), intervals.end(), comp);
        if (0 == intervals.size()) return result;
        temp = intervals[0];
        for (int i = 1; i < intervals.size(); ++i)
        {
            if(intervals[i][0] <= temp[1]) temp[1] = max(temp[1],intervals[i][1]);
            else
            {
                result.push_back(temp);
                temp = intervals[i];
            }
        }
        result.push_back(temp);
        return result;
    }
private:
    static bool comp(const vector<int> &a, const vector<int> &b) 
    {
    return a[0] < b[0];
    }
};
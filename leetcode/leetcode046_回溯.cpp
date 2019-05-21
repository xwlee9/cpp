class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) 
    {
        vector<vector<int>> res;
        vector<int> temp;
        vector<int> visit(nums.size(),0);
        fun(0, nums, temp, visit, res);
        return res;
    }
private:
    void fun(int i, vector<int>& nums,vector<int>& temp,vector<int>& visit, vector<vector<int>>& res)
    {
        // cout << i <<endl;
        if (i == nums.size()) 
        {
            res.push_back(temp);
            return;
        }
        for (int j = 0; j < nums.size(); ++j)
        {
            if (visit[j] == 1) continue;
            temp.push_back(nums[j]);
            visit[j] = 1;
            fun(i+1, nums, temp, visit, res);
            temp.pop_back();
            visit[j] = 0;
        }
    }
};
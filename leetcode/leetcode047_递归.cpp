class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) 
    {
        vector<vector<int>> res;
        if (nums.empty()) return res;
        set<vector<int>> s;
        vector<int> temp;
        vector<int> flag(nums.size(), 0);
        fun(0, nums, s, temp, flag);
        set<vector<int>>::iterator ite = s.begin();
        for(; ite != s.end(); ite++)
        {
            res.push_back(*ite);
        }
        return res;
    }
    void fun(int count, vector<int>& nums, set<vector<int>>& s, vector<int>& temp, vector<int>& flag)
    {
        if (count == nums.size())
        {
            s.insert(temp);
            return;
        }
        for (int i = 0; i < nums.size(); ++i)
        {
            if (flag[i] == 1) continue;
            temp.push_back(nums[i]);
            flag[i] = 1;
            fun(count + 1, nums, s, temp, flag);
            temp.pop_back();
            flag[i] = 0;
        }
    }
};
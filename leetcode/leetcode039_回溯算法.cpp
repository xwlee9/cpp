class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) 
    {
        vector<vector<int> > res;
        vector<int> temp;
        fun(candidates, temp, res, 0, 0,target);
        return res;        
    }
    void fun(vector<int>& candidates, vector<int>& add, vector<vector<int> >& res, int sum, int i, int target)
    {
        if (i > candidates.size()-1 || sum > target) return;
        if (sum == target) 
        {
            res.push_back(add);
            return;
        }
        else 
        {
            sum += candidates[i];
            add.push_back(candidates[i]);
            fun(candidates, add, res, sum, i, target);    
            sum -= candidates[i];
            add.pop_back();
            fun(candidates, add, res, sum, i+1, target); 
        }  
    }
};
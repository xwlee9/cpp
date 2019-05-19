class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) 
    {
        vector<vector<int>> res;
        vector<int> temp;
        int sum = 0;
        fun(k,n, 1, 0, sum, res, temp);
        return res;
    }
    void fun (int k, int n, int i, int count, int &sum,vector<vector<int>>& res, vector<int>& temp)
    {
        if(i > 10) return;
        if(count == k)
        {
            if (sum == n)
            {
                res.push_back(temp);
            }
            return;
        }
        else
        {
            if (sum > n) return;
            sum += i;
            temp.push_back(i);
            fun(k,n,i+1,count+1,sum,res,temp);
            sum -= i;
            temp.pop_back();
            fun(k,n,i+1,count,sum,res,temp);
        }
    }
};
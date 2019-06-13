class Solution {
public:
    vector<int> grayCode(int n) 
    {
        vector<int> res;
        int temp = pow(2,n);
        for(int i = 0; i < temp; ++i)
        {
            res.push_back(i^(i>>1));
        }
        return res;
    }
};
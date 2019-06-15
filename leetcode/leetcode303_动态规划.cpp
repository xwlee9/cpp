class NumArray {
public:
    NumArray(vector<int>& nums) 
    {
        num.push_back(0);
        for (int i = 0; i < nums.size(); ++i)
        {
            num.push_back(num[i] + nums[i]);
        }
    }
    
    int sumRange(int i, int j) 
    {
        return num[j+1] - num[i];
    }
private:
    vector<int> num;
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(i,j);
 */
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) 
    {
        int i = 0;
        int j = numbers.size() - 1;
        while (i < j)
        {
            if(target == numbers[i] + numbers[j]) return {i+1,j+1};
            if(target < numbers[i] + numbers[j]) --j;
            else ++i;
        }
        return {};
    }
};
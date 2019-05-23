class Solution {
public:
    vector<int> plusOne(vector<int>& digits) 
    {
        vector<int> res;
        int c = 1;
        for (int i = digits.size() -1; i >= 0; --i)
        {
            digits[i] += c;
            if (digits[i] == 10)
            {
                digits[i] = 0;
                c = 1;
            }
            else c = 0;
        }
        if (c == 1)
        {
            res.push_back(1);
            for (auto i : digits) res.push_back(i);
        }
        else return digits;
        return res;
    }
};
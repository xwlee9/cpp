class Solution {
public:
    int romanToInt(string s) 
    {
        map<char,int> num{{'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}};
        int val = 0;
        int ret = 0;
        int l = s.size();
        for(int i = 0; i < l-1; ++i)
        {
            val = num[s[i]];
            if (val < num[s[i+1]]) ret -= val;
            else ret += val;
        }
        ret += num[s[l-1]];
        return ret;
    }
};
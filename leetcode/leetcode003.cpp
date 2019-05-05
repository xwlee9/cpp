class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> m(128, -1);
        int res = 0;
        int loc= -1;
        for (int i = 0; i < s.size(); ++i) 
        {
            loc = max(loc, m[s[i]]); //如果出现重复数， loc指向重复数出现的位置
            m[s[i]] = i; // 更新最新出现数字的位置
            res = max(res, i - loc); // 比较之前最大 和 现在最大
        }
        return res;
    }
};
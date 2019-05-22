class Solution {
public:
    bool isMatch(string s, string p) 
    {
        int i = 0;
        int j = 0;
        int si = -1;
        int sj = -1;
        while (i < s.size())
        {
            if(s[i] == p[j] || '?' == p[j])
            {
                ++i;
                ++j;
            }
            else if ('*' == p[j])
            {
                si = i;
                sj = j++;
                         
            }
            else if (si >= 0)
            {
                i = ++si;  // 更新i 通过si ++
                j = sj + 1;  // j依旧保持*的下一位
            }
            else return false;
        } 
        while(j < p.size() && p[j] == '*') ++j;
        return j == p.size();
    }
};
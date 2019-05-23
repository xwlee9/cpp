class Solution {
public:
    char findTheDifference(string s, string t) 
    {
        if (s.empty()) return t[0];
        char res = s[0];
        for (int i = 1; i < s.size(); ++i)
        {
            res = res ^ s[i];
        }
        for (int i = 0; i < t.size(); ++i)
        {
            res = res ^ t[i];
        }
        return res;
    }
};
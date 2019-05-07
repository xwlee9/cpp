class Solution {
public:
    bool isAnagram(string s, string t) 
    {
        int str[128] = {0};
        for(int i = 0; i < s.length(); ++i) str[s[i]] ++;
        for(int i = 0; i < t.length(); ++i) 
        {
            str[t[i]] --;
            if (str[t[i]] < 0) return false;
         }
        for(int i = 97; i < 124; ++i)
        {
            if(str[i] != 0) return false;
        }
        return true; 
    }
};
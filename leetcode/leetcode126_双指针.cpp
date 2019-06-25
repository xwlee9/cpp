class Solution {
public:
    bool isPalindrome(string s) 
    {
        int i = 0;
        int j = s.size() - 1;
        while (i < j)
        {
            while (i < j && !fun(s[i])) ++i;
            while (i < j && !fun(s[j])) --j;
            if (fun2(s[i]) != fun2(s[j])) return false;
            ++i;
            --j;
        }
        return true;
    }
private:
    bool fun(char c)
    {
        if (c <= '9' && c >= '0') return true;
        if (c <= 'Z' && c >= 'A') return true;
        if (c <= 'z' && c >= 'a') return true;
        return false;
    }
    char fun2(char c)
    {
        if (c <= 'Z' && c >= 'A') return c-'A'+'a';
        return c;
    }
};
class Solution {
public:
    string reverseVowels(string s) 
    {
        int i = 0;
        int j = s.size()-1;
        while (i < j)
        {
            while (i < j && fun(s[i])) ++i;
            while (i < j && fun(s[j])) --j;
            if (i >= j) break;
            else 
            {
                swap(s[i], s[j]);
                ++i;
                --j;
            }
        }
        return s;
    }
private:
    bool fun(char c)
    {
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U') return false;
        return true;
    }
};
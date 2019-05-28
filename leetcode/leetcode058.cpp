class Solution {
public:
    int lengthOfLastWord(string s) 
    {
        int i = s.size() - 1;
        int count = 0;
        while (i >= 0 && s[i] == ' ') --i;
        while(i >= 0)
        {
            if (s[i] == ' ') break;
            else count++;
            --i;
        }
        return count;
    }
};
class Solution {
public:
    int strStr(string haystack, string needle) 
    {
        if (needle.length() == 0) return 0;
        int i = 0;
        int m = haystack.length();
        int n = needle.length();
        while (m >= n && i <= m - n)
        {
            int j = 0;
            while (haystack[i+j] == needle[j])
            {
                if (j == needle.size() - 1) return i;
                ++j;
            }
            ++i;
        }
        return -1;
    }
};
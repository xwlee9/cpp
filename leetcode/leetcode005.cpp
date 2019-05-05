class Solution {
public:
    string longestPalindrome(string s) 
    {
        int n = s.size();
        int maxn = 0;
        int start = 0;
        if (n<2) return s;
        for (int i = 0; i < n-1; ++i)
        {
            SearchP(s, i, i, start, maxn, n);
            SearchP(s, i, i+1, start, maxn, n);
        }
        return s.substr(start,maxn);
    }
    void SearchP(string s, int left, int right, int& start, int& maxn, int n)
    {
        while(left >= 0 && right < n && s[left] == s[right])
        {
            left--;
            right ++;
        }
        if (maxn < right - left -1)
        {
            start = left + 1;
            maxn = right - left - 1;
        }
    }
};

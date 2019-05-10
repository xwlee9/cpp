#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) 
    {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int kids = 0;
        int cookie = 0;
        while (kids < g.size() && cookie < s.size())
        {
            if (g[kids] <= s[cookie]) ++kids;
            ++cookie;
        }
        return kids;  
    }
};
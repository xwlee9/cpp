#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;


class Solution {
public:
    int longestPalindrome(string s) 
    {
        int char_map[128] = {0};
        int flag = 0;
        int max_length = 0;
        for (int i = 0; i < s.length(); ++i)  char_map[s[i]] += 1;
        for (int i = 65; i < 128; ++i)
        {
            if (char_map[i] % 2 == 0) max_length += char_map[i];
            else 
            {
                max_length += char_map[i] - 1;
                flag = 1;
            }
        }
        return max_length + flag;
    }
};
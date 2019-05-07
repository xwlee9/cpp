#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;

class Solution {
public:
    bool wordPattern(string pattern, string str) 
    {
        vector<string> store;
        map<string, char> pt;
        char used[128] = {0};
        string temp;
        int pos = 0;
        int len = pattern.length();
        str += ' ';
        for (int i = 0; i < str.length(); ++i)
        {
            if (str[i] == ' ') 
            {
                if(pos == len) return false;  // str > pattern
                if(pt.find(temp) == pt.end() )   // 没有查到此key
                {
                    if(used[pattern[pos]] == 1) return false;
                    pt.insert(pair<string, char>(temp, pattern[pos]));
                    used[pattern[pos]] = 1; 
                }
                else  // 如果查到此key
                {
                    if(pt[temp] != pattern[pos])   return false;
                }
                temp = "";
                pos++;
            }
            else  temp += str[i];
        }
        if (pos != len) return false;
        return true;
    }
};
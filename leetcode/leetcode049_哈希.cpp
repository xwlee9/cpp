#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
using namespace std;

// 也可以使用 one hot code
class Solution {
public:
    vector<vector<string> > groupAnagrams(vector<string>& strs) 
    {
        map<string, vector<string> > anagram;
        vector<vector<string> > result;
        for (int i = 0; i < strs.size(); ++i)
        {
            string str = strs[i];
            sort (str.begin(), str.end());
            if (anagram.find(str) == anagram.end())  
            {
                vector<string> item;
                anagram[str] = item; 
            }
            anagram[str].push_back(strs[i]);
        }
        map<string, vector<string> > :: iterator ite;
        for (ite = anagram.begin(); ite != anagram.end(); ++ite)
        {
            result.push_back((*ite).second);
        }
    return result;   
    }
};
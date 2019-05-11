class Solution {
public:
    vector<string> letterCombinations(string digits) 
    {
        vector<string> result;
        vector<string> dict{"", "*", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        if(digits.empty()) return result;
        fun(dict, result, 0, "", digits);
        return result;
    }
private:
    void fun(vector<string>& dic, vector<string>& result, int level, string out, string digits)
    {
        if(level == digits.size() ) 
        {
            result.push_back(out);
            return;
        }
        string s = dic[digits[level] - '0'];
        for(int i = 0; i < s.length(); ++i)
        {
            fun(dic, result, level + 1, out + s[i], digits);
        }
    }
};
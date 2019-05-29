class Solution {
public:
    bool isNumber(string s) 
    {
        bool num = false;  // 数字
        bool numExp = true;  // e后面数字
        bool dot = false;   // 点
        bool exp = false;  // e
        bool sign = false;  // 正负号
        int n = s.size();
        for(int i = 0; i < n; ++i)
        {
            if (s[i] == ' ')
            {
                if (i < n-1 && s[i+1] != ' ' && (num || dot || exp || sign)) return false;
            }
            else if (s[i] == '+' || s[i] == '-')
            {  // 如果不在第一位 并且前面不是e 前面不是空 错误
                if (i > 0 && s[i-1] != 'e' && s[i-1] != ' ') return false;
                sign = true;
            }
            else if (s[i] >= '0' && s[i] <= '9')
            {
                num = true;
                if (exp) numExp = true;  
            }
            else if (s[i] == '.')
            {
                if (dot || exp) return false;   // 如果之前存在. 或是 e 返回false
                dot = true;
            }
            else if (s[i] == 'e')
            {
                if (exp || !num) return false;  // 如果之前存在e 或者前面没有数字 返回false
                exp = true;
                numExp = false;  // 确保后面有数字
            }
            else return false;
        }
        return num && numExp;
    }
};
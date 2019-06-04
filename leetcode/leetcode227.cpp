class Solution {
public:
    int calculate(string s) 
    {
        vector<int> st;
        long long num = 0;
        char sign = '+';
        for (int i = 0; i < s.size(); ++i)
        {
            // if (s[i] == ' ') continue;
            if (s[i] >= '0') 
            {
                num = num * 10 - '0' + s[i];
            }
            if ((s[i] < '0' && s[i] != ' ') || i == s.size()-1)
            {
                if (sign == '+') st.push_back(num);
                else if (sign == '-') st.push_back(0 - num);
                else if (sign == '*')
                {
                    int temp = st.back();
                    st.pop_back();
                    st.push_back(temp * num);
                }
                else if (sign == '/')
                {
                    int temp = st.back();
                    st.pop_back();
                    st.push_back(temp / num);
                }
                sign = s[i]; // 保存为上一个符号
                num = 0;
            }
        }
        long long res = 0;
        for (int i = 0; i < st.size(); ++i)
        {
            // cout << st[i] << endl;
            res += st[i];
        }
        return res;  
    }
// private:
//     int fun(int& i, string s)
//     {
//         long long t = 0;
//         while (i < s.size() && (s[i] >= '0' || s[i] == ' '))
//         {
//             if (s[i] != ' ')  t = t * 10 + s[i]-'0';
//             ++i;
//         }
//         --i;
//         return t;
//     }
    
};
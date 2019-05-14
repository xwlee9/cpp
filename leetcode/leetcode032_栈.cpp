class Solution {
public:
    int longestValidParentheses(string s) 
    {
        vector<int> st;
        int res = 0;
        int temp = 0;
        for (int i = 0; i < s.length(); ++i)
        {
            if(s[i] == '(') st.push_back(i);
            else // if(s[i] == ')')
            {
                if (st.empty()) temp = i+1;
                else  // if (st.top() == '(' ) 
                {
                    st.pop_back();
                    res = st.empty() ? max(res, i - temp + 1) : max(res, i - st.back());
                }
            }
        }
        return res;
    }
};
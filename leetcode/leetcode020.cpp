class Solution {
public:
    bool isValid(string s) 
    {
        stack<char> temp;
        temp.push('x');
        for(int i = 0; i < s.length(); ++i)
        {
            // if ((temp.top() == '(' && s[i] == ')') || (temp.top() == '[' && s[i] == ']') || (temp.top() == '{' && s[i] == '}'))
            if (temp.top() + 1 == s[i] || temp.top() + 2 == s[i])  // ascii码中 （）差1 [] {} 差2
            {
                temp.pop();
                continue;
            }
            temp.push(s[i]);
        }
        if(temp.top() == 'x') return true;
        return false;
    }
};
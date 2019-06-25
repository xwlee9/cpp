class Solution {
public:
    bool validPalindrome(string s) 
    {
        return fun(s, 0, 0, s.size()-1);
    }
private:
    bool fun(string s, int count, int i, int j)
    {
         while (i <= j)
        {
            // cout << i << j << endl;
            if (count > 1) return false;
            if (s[i] != s[j])
            {
                return fun(s, count+1, i+1, j) || fun(s, count+1, i, j-1);
            }
            ++i;
            --j;
        }
        return true;      
    }
};
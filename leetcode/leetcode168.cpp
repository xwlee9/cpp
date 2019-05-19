class Solution {
public:
    string convertToTitle(int n) 
    {
        string temp;
        string res;
        while(n)
        {
            n --;
            int i = n % 26;
            // cout << i;
            n = n / 26;
            temp += (char)(i + 'A');
        }
        for (int i = temp.length()-1; i >= 0; --i) res += temp[i];
        return res;
    }
};
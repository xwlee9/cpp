class Solution {
public:
    string countAndSay(int n) 
    {
        string res;
        if (n <= 0) return res;
        res = '1';
        while(--n)
        {
            string temp;
            for (int i = 0; i < res.length(); ++i)
            {
                int count = 1;
                while(i < res.length() - 1 && res[i] == res[i+1])
                {
                    count ++;
                    ++i;
                }
                temp += (char)(count + '0');
                temp += res[i];
            }
            res = temp;
        }
        return res;
    }

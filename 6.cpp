class Solution {
public:
    string convert(string s, int numRows) 
    {
        if(numRows < 2) return s;

        string res = "";
        int size = numRows * 2 - 2;
        for (int i = 0; i < numRows; ++i)
        {
            for(int j = i; j < s.size(); j+=size)
            {
                res += s[j];
                int temp = j + size - 2*i;
                if (i != 0 && i != numRows - 1 && temp < s.size()) res += s[temp]; 

            }
        } 
        return res;
    }
};
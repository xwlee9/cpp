class Solution {
public:
    string convertToBase7(int num) 
    {
        if (num == 0) return "0";
        string res;
        string temp;
        if (num < 0) res +="-";
        int n = abs(num);
        while(n > 0)
        {
            temp += n%7 + '0';
            n = n / 7;
        }
        for (int i = temp.size()-1; i >= 0; --i) res+= temp[i];
        return res;
    }
};
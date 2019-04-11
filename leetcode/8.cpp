class Solution {
public:
    int myAtoi(string str) 
    {
        int flag = 1;
        long long res = 0;
        int i = 0;
        int n = str.size();
        int tag = 0;
        while(i<n && str[i] ==' ')
        {
            ++i;
        }
        if (i<n)
        {
            if (str[i] == '+') 
            {
                flag = 1;
                tag ++;
            }
            if (str[i] == '-')
            {
                flag = -1;
                tag ++;
            }
        }
        i += tag;
        if (i > n) return 0;
        while (i < n && str[i] >= '0' && str[i] <= '9')
        {
            res = res * 10 + str[i] - '0';
            if (res > INT_MAX || -res < INT_MIN) return (flag == 1) ? INT_MAX : INT_MIN;
            ++i;
        }
        return flag * res;
    }
};
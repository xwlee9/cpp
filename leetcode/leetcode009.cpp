class Solution {
public:
    bool isPalindrome(int x) 
    {
        int temp = x;
        long long res = 0;
        // int 
        while (temp>0)
        {
            res = res*10 + temp % 10;
            temp /= 10;
        }
        if (res > INT_MAX || res < INT_MIN) return false;
        return x == res; 
    }
};
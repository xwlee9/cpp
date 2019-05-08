class Solution {
public:
    bool isPerfectSquare(int num) 
    {
        // int x = 0;
        // while ((long long) x * x < INT_MAX && x * x <= num)
        // {
        //     if (x*x == num) return true;
        //     ++ x;
        // }
        // return false;
        int x = 1;
        while (num >= 0)
        {
            if(num == 0) return true;
            num -= x;
            x += 2;
        }
        return false;
    }
};
class Solution {
public:
    bool isHappy(int n) 
    {
        if (n <= 9)
        {
            if (n == 1 || n == 7) return true;  // 在小于9的情况下 只有1 和7 是快乐数
            else return false;
        }
        int temp = 0;
        while (n)
        {
            int a = n % 10;
            temp += a * a;
            n = n / 10;
        }
        n = temp;
        return isHappy(n);
    }
};
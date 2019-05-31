class Solution {
public:
    int addDigits(int num) 
    {
        if (num == 0) return 0;
        return (num % 9 ? num % 9 : 9);  // f(10a+b) = f(9a + a+b) = f(a+b)  减少的差值为9a 保证差值可以被9整除
    }
};
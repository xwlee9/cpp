class Solution {
public:
    int findNthDigit(int n) 
    {
        // if (n <= 9)return n;
        long long num = 0;
        int i = 1;  // i 为几位数
        int last = num;
        while (n > num)
        {
            last = num;
            num = num + 9 * i * pow (10,i-1);
            ++i;
        }
        --i;
        int diff = n - last;
        int temp = (diff+i-1) % i;
        diff = (diff-1) / i;
        int m = pow(10,i-1) + diff;
        // cout << m << i << " " << temp << endl;
        while (temp != 0)
        {
            m = m % (int)pow(10,i-1);
            // cout << m << endl;
            temp --;
            i --;
        }
        // cout << m << i << endl;
        return m/pow(10,i-1);
    }
};
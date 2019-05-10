class Solution {
public:
    int findComplement(int num) 
    {
        long long x = 1;
        int temp = num;
        while(temp > 0) 
        {
            temp >>= 1;
            x <<= 1;                              
        }
        return (x-1) xor num;
    }
};
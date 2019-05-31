class Solution {
public:
    int singleNumber(vector<int>& nums) 
    {
        int a = 0;  // 利用真值表  出现1次的个数
        int b = 0;  // 计算出现 2次个数  
        for (auto x : nums)
        {
            a = (a ^ x) & ~b;   // a 计算x出现1次个数 出现1次时 a = a^x       2次时 b为0，a为再次异或x为0     3次时 b为非0 a = 0
            b = (b ^ x) & ~a;  //x出现1次时 a非0， b为0     2次时 a为0, b = b^x    3次时 a为0 b为再次异或x为0;
        }
        return a;
    }
};
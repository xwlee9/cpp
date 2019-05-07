class Solution {
public:
    bool canWinNim(int n) {
        return (n % 4 == 0) ? false:true;
    }
};
// 巴什博奕，n%(m+1)!=0时，先手总是会赢

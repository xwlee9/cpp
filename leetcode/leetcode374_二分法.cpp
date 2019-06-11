// Forward declaration of guess API.
// @param num, your guess
// @return -1 if my number is lower, 1 if my number is higher, otherwise return 0
int guess(int num);

class Solution {
public:
    int guessNumber(int n) 
    {
        long long i = 1;
        long long j = n;
        while (i <= j)
        {
            int mid = (i+j) / 2;
            // cout << mid << endl;
            if (guess(mid) == 0) return mid;
            if (guess(mid) == 1) i = mid + 1;
            else j = mid - 1;
        }
        return 1;
    }
};
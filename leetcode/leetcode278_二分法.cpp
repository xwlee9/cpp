// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) 
    {
        return fun(1, n);
    }
private:
    int fun(long long i, long long j)
    {
        if (i > 1 && !isBadVersion(i-1) && isBadVersion(i)) return i;
        else if (i > j) return 1;
        int  mid = (i + j) / 2;
        // cout << mid << endl;
        if (isBadVersion(mid)) j = mid - 1;
        else i = mid+1;
        return fun(i, j);
    }
};
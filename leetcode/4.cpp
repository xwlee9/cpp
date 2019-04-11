class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) 
    {
        int n1 = nums1.size();
        int n2 = nums2.size();
        int left = (n1 + n2 + 1) / 2;
        int right = (n1 + n2 + 2) / 2;
        return (findms(nums1, 0, nums2, 0, left, n1, n2) + findms(nums1, 0, nums2, 0, right, n1, n2))/2.0;
    }
    int findms(vector<int>& nums1, int i ,vector<int>& nums2, int j, int k, int n1, int n2)
    {               // 使用两个变量i和j分别来标记数组nums1和nums2的起始位置
        if (i >= n1) return nums2[j + k -1];  // nums1 为空
        if (j >= n2) return nums1[i + k -1];
        // 此时nums1 nums2 均不为空 k = 1 ===> nums1 nums2 均为 1
        if (k == 1) return min(nums1[i],nums2[j]); //
        // 使用二分法 k/2查找 若k/2-1 >= n1 ===> k>= 2n1+2 中位数肯定不在n1里面
        int midVal1  = (i + k/2 -1 < n1) ? nums1[i + k/2 -1] : INT_MAX;
        int midVal2  = (j + k/2 -1 < n2) ? nums2[j + k/2 -1] : INT_MAX;
        if (midVal1 < midVal2)
        {
            // cout << midVal1 << "  1  " << k << endl;
            // cout << midVal2 <<endl;
            // 如果第一个数组的第K/2个数字小的话，那么说明要找的数字肯定不在nums1中的前K/2中===》淘汰，
            // 将nums1的起始位置向后移动K/2个，并且此时的K也自减去K/2，调用递归。
            return findms(nums1, i + k/2, nums2, j, k-k/2, n1, n2);
        }
        else
            // cout << midVal1 << "  2  " << k << endl;
            // cout << midVal2 <<endl;
        {
            return findms(nums1, i, nums2, j + k/2, k-k/2, n1, n2);
        }
    }
};
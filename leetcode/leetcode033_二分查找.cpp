#include <algorithm>
#include <vector>
using namespace std;

// 使用nums begin mid end 比较 判断是不是旋转空间
class Solution {
public:
    int search(vector<int>& nums, int target) 
    {
        int begin = 0;
        int end   = nums.size()-1;
        int tag = 1;
        if (end < 0) return -1;
        // if (end == 0) 
        // {
        //     if (target == nums[0]) return 0;
        //     else return -1;
        // }
        int mid = -1;
        while (begin <= end)
        {
            mid = (begin + end) / 2;
            if (nums[begin] < nums[mid]) begin = mid;
            else if (nums[mid] < nums[end])  end = mid;
            if (nums[mid] == nums[begin] && nums[mid] == nums[end] ) 
            {
                tag = 0;
                break;
            }
            if (nums[mid] > nums[mid+1]) break;
        }
        // return mid;
        if (target >= nums[0])
        {
            begin = 0;
            end = mid;
            if(tag == 0) end = nums.size()-1;
            while (begin <= end)
            {
                int m = (begin + end) / 2;
                if (target == nums[m])  return m;
                if (target > nums[m]) begin = m+1;
                if (target < nums[m]) end = m-1; 
            }
        }
        if (target < nums[0])
        {
            begin = mid+1;
            end = nums.size()-1;
            if(tag == 0) begin = 0;
            if (target < nums [begin]) return -1; 
            while (begin <= end)
            {
                int m = (begin + end) / 2;
                if (target == nums[m])  return m;
                if (target > nums[m]) begin = m+1;
                if (target < nums[m]) end = m-1;
            }
        } 
        return -1;
    }
};
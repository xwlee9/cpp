#include <iostream>
#include <queue>
using namespace std;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) 
    {
        priority_queue<int, vector<int>, greater<int> > q; // 使用最小堆构造 保留k个 那么父节点就是第k大的值
        for(int i = 0; i < nums.size(); ++i)
        {
            if  (q.size() < k) q.push(nums[i]);
            else if (q.top() < nums[i])
            {
                q.pop();
                q.push(nums[i]);
            }
        }
        return q.top();       
    }
};
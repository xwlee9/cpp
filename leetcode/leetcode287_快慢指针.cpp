class Solution {
public:
    int findDuplicate(vector<int>& nums) 
    {
        int fast = 0;
        int slow = 0;
        while (1)
        {
            fast = nums[nums[fast]];
            slow = nums[slow];
            if (slow == fast) break;
        }
        fast = 0;
        while (fast != slow)
        {
            fast = nums[fast];
            slow = nums[slow];            
        }
        return slow;
    }
};

/*
2*(a+b) == a+b+c+b ==> a == c 
*/
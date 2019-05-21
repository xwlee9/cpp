class Solution {
public:
    int trap(vector<int>& height) 
    {
        int i = 0;
        int j = height.size()-1;
        int res = 0; 
        while(i < j)
        {
            int min_val = min(height[i], height[j]);
            if (min_val == height[i])
            {
                ++i;
                while(i < j && height[i] < min_val) res += min_val - height[i++];
            }
            else
            {
                --j;
                while(i < j && height[j] < min_val) res += min_val - height[j--];
            }
        }
        return res;
    }
};
class Solution {
public:
    int maxArea(vector<int>& height) 
    {
        int j = height.size()-1;
        int i = 0;
        int res = 0;
        while (i < j)
        {
            res = max(res, min(height[i],height[j]) * (j - i));
            if (height[i] < height[j]) i++;
            else j--;
        }
        return res;
    }
};
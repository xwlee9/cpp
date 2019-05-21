#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;


class NumArray {
public:
    NumArray(vector<int>& nums) 
    {
        if (nums.empty()) return;
        int n = nums.size() * 4;  // 一般线段树数组的大小是原来数组大小的四倍
        for (int i = 0; i < n; ++i) _value.push_back(0);
        _right_end = nums.size() - 1;
        build_segment_tree(_value, nums, 0, 0, _right_end);
    }
    void update(int i, int val) 
    {
       update_segment_tree(_value, 0, 0, _right_end, i, val); 
    }
    
    int sumRange(int i, int j) 
    {
         return sum_range_segment_tree(_value, 0, 0, _right_end, i, j);
    }
private:
    vector<int> _value;
    int _right_end;
    void build_segment_tree(vector<int>& value, vector<int>& nums, int pos, int left, int right)
    {
        if(left == right)
        {
            value[pos] = nums[left];
            return;
        }
        int mid = (left + right) / 2;
        build_segment_tree(value, nums, pos * 2 + 1, left, mid);
        build_segment_tree(value, nums, pos * 2 + 2, mid+1, right);
        value[pos] = value[pos*2+1] + value[pos*2+2];
    }

    void print_segment_tree(vector<int>& value, int pos, int left, int right, int layer)
    {
        for (int i = 0; i < layer; ++i) printf("----");
        printf("[%d %d][%d] : %d\n", left, right, pos, value[pos]);
        if (left == right) return;
        int mid = (left + right) / 2;
        print_segment_tree(value, pos*2+1, left, mid, layer+1);
        print_segment_tree(value, pos*2+2, mid+1, right, layer+1);
    }
    int sum_range_segment_tree(vector<int>& value, int pos, int left, int right, int qleft, int qright)
    {
        if(qright < left || qleft > right) return 0;
        if(qleft <= left && qright >= right) return value[pos];
        int mid = (left + right) / 2;
        return sum_range_segment_tree(value, pos*2+1, left, mid, qleft, qright) + sum_range_segment_tree(value, pos*2+2, mid+1, right, qleft, qright); 
    }
    void update_segment_tree(vector<int>& value, int pos, int left, int right, int index, int new_value)
    {
        if (left == right && index == left)
        {
            value[pos] = new_value;
            return;
        }
        int mid = (left + right) / 2;
        if (index <= mid) update_segment_tree(value, pos*2+1, left, mid, index, new_value);
        else update_segment_tree(value, pos*2+2, mid+1, right, index, new_value);
        value[pos] = value[pos*2+1] + value[pos*2+2];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(i,val);
 * int param_2 = obj->sumRange(i,j);
 */
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

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
int main()
{
    vector<int> value(12, 0);
    vector<int> nums;
    nums.push_back(0);
    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(3);
    nums.push_back(4);
    nums.push_back(5);
    build_segment_tree(value, nums, 0, 0, 5);
    print_segment_tree(value, 0, 0, 5, 0);
    int sum = sum_range_segment_tree(value, 0, 0, 5, 1, 3);
    printf("%d\n", sum);
    update_segment_tree(value, 0, 0, 5, 2, 10);
    print_segment_tree(value, 0, 0, 5, 0);
    return 0;
}

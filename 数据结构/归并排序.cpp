#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
#include <string>
#include <time.h>
using namespace std;

void merge_sort_two_vec(vector<int>& sub_vec1, vector<int>& sub_vec2, vector<int>& vec)
{
    int i = 0;
    int j = 0;
    while (i < sub_vec1.size() && j < sub_vec2.size())
    {
        if(sub_vec1[i] <= sub_vec2[j])
        {
            vec.push_back(sub_vec1[i]);
            ++i;
        }
        else
        {
            vec.push_back(sub_vec2[j]);
            ++j;
        }
    }
    for(; i < sub_vec1.size(); ++i) vec.push_back(sub_vec1[i]);
    for(; j < sub_vec2.size(); ++j) vec.push_back(sub_vec2[j]);
}

void merge_sort(vector<int> &vec)
{
    if (vec.size() < 2) return;
    int mid = vec.size()/2;
    vector<int> sub_vec1;
    vector<int> sub_vec2;
    for (int i = 0; i < mid; ++i) sub_vec1.push_back(vec[i]);
    for (int i = mid; i < vec.size(); ++i) sub_vec2.push_back(vec[i]);  // 获取右序列
    merge_sort(sub_vec1);
    merge_sort(sub_vec2);
    vec.clear();
    merge_sort_two_vec(sub_vec1, sub_vec2, vec);
}

int main()
{
    vector<int> vec;
    srand(time(NULL));
    for (int i = 0; i < 1000; ++i) vec.push_back((rand()*rand()) % 1005);
    merge_sort(vec);
    for (int i = 0; i < 1000; ++i) cout << vec[i];
    cout << endl;
    return 0;
}
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;



class Solution {
public:
    string removeKdigits(string num, int k) 
    {
        vector<int> vec;  // 使用vector模拟栈
        string result = "";  // 存储最终结果
        for(int i = 0; i < num.length(); ++i)  // 高位循环扫描数字
        {
            int number = num[i] - '0';
            while (vec.size()!=0 && k > 0 && number < vec.back())  // 第i位比第i-1位小 删除第i-1位
            {
                vec.pop_back();
                --k;
            }
            if (number != 0 || vec.size() != 0)  vec.push_back(number);   // 栈为空 遇到0 不添加 其他情况全部进栈 
        }
        while (vec.size()!=0 && k > 0)  // 当k仍有第时候 说明仍需要删除数字 从地位往高位删
        {
            vec.pop_back();
            --k;
        }
        for (int i = 0; i < vec.size(); ++i)  result.append(1, vec[i]+'0');  // 循环
        if (result == "") result = "0";
        return result;
    }
};
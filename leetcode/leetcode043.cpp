#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
#include <set>
using namespace std;



class Solution {
public:
    string multiply(string num1, string num2) 
    {
        vector <int> s;
        for (int i = 0; i < num2.length(); ++i) s.push_back(0);
        string result;
        int h = 0;
        for(int i = num1.length() - 1; i >= 0; --i)  // 乘法 num1 在下 num2 在上
        {
            int c = 0;  // 进位为0
            int temp1 = num1.length()-1-i;  // num1的第temp1低位
            int n1 = num1[i] - '0';  // 转成数字
            vector <int> s1;  // 记录每以为num1
            for (int j = num2.length() - 1; j >= 0; --j)
            {
                int temp2 = num2.length()-1-j;  // num2的第temp2低位
                int n2 = (num2[j] - '0') * n1 + c;  // 每一位乘
                c = n2 / 10;  // 进位
                s1.push_back(n2 % 10);  // 入栈
            }
            s1.push_back(c);  // 加入进位
            s.push_back(h);  // 将s操作位提高
            for (int k = 0; k < s1.size(); ++k)
            {
                int temp = (int)s[k+temp1] + (int)s1[k] + (int)h;  // 相加
                h = temp / 10;  // 加法的进位
                s[k+temp1] = temp % 10;  // 每一位数字
            }
        }
        if (h != 0) s.push_back(h);
        while (s.back() == 0) 
        {
            s.pop_back();
            if (s.empty()) return "0";  
        }
        while (!s.empty())
        {
            result += (s.back() + '0');
            s.pop_back();
        }  
        return result;
    }
};
#include <iostream>
#include <stack>
#include <string>
using namespace std;

void compute(stack<int>& number_stack, stack<char>& operation_stack)
{
    if (number_stack.size() < 2) return; // 如果数字少于2个 ==>直接推出
    int num2 = number_stack.top();
    number_stack.pop();
    int num1 = number_stack.top();
    number_stack.pop();
    if (operation_stack.top() == '+') number_stack.push(num1 + num2);
    if (operation_stack.top() == '-') number_stack.push(num1 - num2);
    operation_stack.pop();
}
class Solution {
public:
    int calculate(string s) 
    {
        static const int STATE_BEGIN = 0;
        static const int STATE_NUMBER = 1;
        static const int STATE_OPERATION = 2;

        stack<int> number_stack; 
        stack<char> operation_stack;
        long long num = 0;
        int STATE = STATE_BEGIN;
        int compuate_flag = 0;

        for(int i = 0; i < s.size(); ++i)
        {
            if (s[i] == ' ') continue;
            switch (STATE)
            {
                case STATE_BEGIN:
                    if (s[i] >= '0' && s[i] <= '9') STATE = STATE_NUMBER;
                    else STATE = STATE_OPERATION;
                    i--;
                    break;
                case STATE_NUMBER:
                    if (s[i] >= '0' && s[i] <= '9') num = num * 10 + s[i] - '0'; 
                    else
                    {
                        number_stack.push(num);
                        if (compuate_flag == 1) compute(number_stack, operation_stack);
                        num = 0; // 重置num 往回一次 重新进入operate状态
                        --i;
                        STATE = STATE_OPERATION;
                     }
                     break;
                case STATE_OPERATION:
                    if (s[i] == '+' || s[i] == '-') // 有运算符之后 就可以运算 计算状态为1 
                    {
                        operation_stack.push(s[i]);
                        compuate_flag = 1;
                    }
                    else if(s[i] == '(') // 右括号 计算状态为0
                    {
                        STATE = STATE_NUMBER;
                        compuate_flag = 0;
                    }
                    else if(s[i] >= '0' && s[i] <= '9') // 切换状态 减1从新在number中计算
                    {
                        STATE = STATE_NUMBER;
                        --i;
                    }
                    else if (s[i] == ')') compute(number_stack, operation_stack); // 有右括号 计算
                    break;
            }
        }
        if (num != 0) // 如果没有运算符 ===> 
        {
            number_stack.push(num);
            compute(number_stack, operation_stack);
        }
        if (num == 0 && number_stack.empty()) return 0;
        return number_stack.top();        
    }
};


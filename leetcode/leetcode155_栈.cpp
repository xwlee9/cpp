#include <iostream>
#include <stack>
using namespace std;

class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {
        
    }
    
    void push(int x) 
    {
        _data.push(x);
        if (min.empty()) min.push(x);
        else
        {
            if(x > min.top()) x = min.top();
            min.push(x);
        }       
    }
    
    void pop() {
        _data.pop();
        min.pop();  
    }
    
    int top() {
        return _data.top();  
    }
    
    int getMin() 
    {
        return min.top();
    }
private:
    stack<int> _data;
    stack<int> min;
};
/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
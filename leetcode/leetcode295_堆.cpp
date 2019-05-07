#include <iostream>
#include <queue>
using namespace std;

class MedianFinder  // 一个最大堆 一个最小堆 最大堆比最小堆的父节点 小
{
public:
    /** initialize your data structure here. */
    MedianFinder() 
    {
        
    }
    
    void addNum(int num) 
    {
        if(big_heap.empty()) 
        {
            big_heap.push(num);
            return;
        }
        if (big_heap.size() == small_heap.size())
        {
            if (num < big_heap.top()) big_heap.push(num);
            else small_heap.push(num);
        }
        else if (big_heap.size() < small_heap.size())
        {
            if (num > small_heap.top()) 
            {
                big_heap.push(small_heap.top());
                small_heap.pop();
                small_heap.push(num);
            }
            else big_heap.push(num);
        }
        else if (big_heap.size() > small_heap.size())
        {
            if (num < big_heap.top()) 
            {
                small_heap.push(big_heap.top());
                big_heap.pop();
                big_heap.push(num);
            }
            else small_heap.push(num);
        }   
    }
    
    double findMedian() 
    {
        if (big_heap.size() > small_heap.size()) return big_heap.top();
        if (big_heap.size() < small_heap.size()) return small_heap.top();
        if (big_heap.size() == small_heap.size()) return (big_heap.top()+small_heap.top())/2.0;
        return 0;
    }
        
private:
    priority_queue<int> big_heap;
    priority_queue<int, vector<int>, greater<int> > small_heap; 
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
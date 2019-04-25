#include <iostream>
#include <queue>
using namespace std;

int main()
{
    priority_queue<int> big_heap; //默认构造为最大堆
    priority_queue<int, vector<int>, greater<int> > small_heap; // 最小堆构造
    priority_queue<int, vector<int>, less<int> > big_heap2; // 最大堆构造
    if (big_heap.empty())  cout << "big_head is empty!!!" << endl;
    int test[] = {6,10,1,7,98,5,32};
    for (int i = 0; i < 7; ++i) big_heap.push(test[i]);
    cout << "big_heap.top = " << big_heap.top() << endl;
    big_heap.push(1000);
    cout << "big_heap.top = " << big_heap.top() << endl;
    for (int i = 0; i < 3; ++i) big_heap.pop();
    cout << "big_heap.top = " << big_heap.top() << endl;
    cout << "big_heap.size = " << big_heap.size() << endl;

    return 0;
}
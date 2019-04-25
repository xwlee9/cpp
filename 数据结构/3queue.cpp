#include <iostream>
#include <queue>
using namespace std;
int main()
{
    queue<int> q;
    if(q.empty()) cout << "q is empty" <<endl;
    q.push(5);
    q.push(6);
    q.push(10);
    cout << "q.front is :" << q.front() << endl;
    q.pop();
    cout << "q.front is :" << q.front() << endl;
    cout << "q.back is :" << q.back() << endl;
    cout << "q.size is :" << q.size() << endl;
    return 0;
}
    

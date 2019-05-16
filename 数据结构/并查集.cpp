#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <set>
using namespace std;

class DisjoinSet
{
public:
    DisjoinSet(int n)
    {
        for (int i = 0; i < n; ++i)
        {
            _id.push_back(i);
            _size.push_back(1);
        }
        _count = n; 
    }
    int find(int p)
    {
        while(p != _id[p])
        {
            _id[p] = _id[_id[p]];  // 查找进行路径压缩 当p与当前集合id[p]不同时 循环 将p的父节点id[p]更新为id[p]的父节点id[id[p]]
            p = _id[p];
        }
        return p;
    }
    void un(int p, int q)
    {
        int i = find(p);
        int j = find(q);
        if (i == j) return;
        if (_size[i] < _size[j])
        {
            _id[i] = j;
            _size[j] += _size[i];
        }
        else
        {
            _id[j] = i;
            _size[i] += _size[j];
        }
        _count--;
    }

    void print_set()
    {
        cout << "元素";
        for (int i = 0; i < _id.size(); ++i) cout << i << " ";
        cout << endl;
        cout << "集合";
        for (int i = 0; i < _id.size(); ++i) cout << _id[i] << " ";
        cout << endl;
    }

private:
    vector<int> _id;
    vector<int> _size;
    int _count;
};

int main()
{
    cout << "***********"  << endl;
    DisjoinSet test1(9);
    test1.print_set();
    test1.un(0,5);
    test1.print_set();
    cout << test1.find(0) << " " << test1.find(2) << endl;
    cout << test1.find(0) << " " << test1.find(5) << endl;
    test1.un(1,2);
    test1.un(0,3);
    test1.un(5,7);
    test1.print_set();
    test1.un(0,1);
    test1.print_set();
    return 0;
}
#include <iostream>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
};

int main()
{
    ListNode a;
    ListNode b;
    ListNode c;
    ListNode d;
    ListNode e;
    a.val = 10;
    b.val = 20;
    c.val = 30;
    d.val = 40;
    e.val = 50;

    a.next = &b;
    b.next = &c;
    c.next = &d;
    d.next = &e;
    e.next = NULL;

    ListNode* head = &a;
    while (head)
    {
        cout << head->val <<endl;
        head = head->next;
    }
    return 0;
}



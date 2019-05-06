#include <iostream>
#include <set>
using namespace std;

struct  ListNode
{
    int val;
    ListNode *next;
    ListNode(int x): val(x), next(NULL){}
};

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) 
    {
        set<ListNode*> node_set;
        while(headA)
        {
            node_set.insert(headA);
            headA = headA -> next;
        }
        while(headB)
        {
            if(node_set.find(headB) != node_set.end()) return headB;
            headB = headB -> next;
        }
        return NULL;
    }
};

// 先找他们两个较长的 指针指向长链表的 和短链表的等长处 然后AB一起指向下一个


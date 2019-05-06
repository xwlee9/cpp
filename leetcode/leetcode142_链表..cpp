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
// 使用set 插入链表的地址 即 遍历时插入节点前 在set中查询 第一个在set()中发现的节点地址 就是链表的起点 
// class Solution {
// public:
//     ListNode *detectCycle(ListNode *head) {
//         set<ListNode*> node_set;
//         while (head)
//         {
//             if (node_set.find(head) != node_set.end())  return head;
//             node_set.insert(head);
//             head = head -> next;
//         }
//         return NULL; 
//     }
// };
// 快慢指针 快指针速度是慢指针的2倍 两者是相遇的地点meet 分别冲head 和 meet出发 两个指针速度一样 相遇为环的起点
// head -> start ==> a     start -> meet ==> b  meet -> start ==> c
// 2 * (a + b) = a + b + c + b   ===> b = c 

class Solution {
public:
    ListNode *detectCycle(ListNode *head) 
    {
        ListNode *fast = head;
        ListNode *slow = head;
        ListNode *meet = NULL;
        while (fast)
        {
            slow = slow->next;
            fast = fast->next;
            if (!fast) return NULL;
            fast = fast->next;
            if (fast == slow)
            {
                meet = fast;
                break;
            }
        }
        if (meet == NULL) return NULL;
        while(head && meet)
        {
            if(head == meet) return head;
            head = head->next;
            meet = meet->next;
        }
        return NULL;
    }
};
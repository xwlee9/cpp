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
    bool hasCycle(ListNode *head) 
    {
        ListNode *fast = head;
        ListNode *slow = head;
        // ListNode *meet = NULL;
        while (fast)
        {
            slow = slow->next;
            fast = fast->next;
            if (!fast) return false;
            fast = fast->next;
            if (fast == slow)
            {
                // meet = fast;
                return true;
            }
        }
        // if (meet == NULL) return NULL;
        // while(head && meet)
        // {
        //     if(head == meet) return head;
        //     head = head->next;
        //     meet = meet->next;
        // }
        return false;
    }
};
// 快慢指针 快指针速度是慢指针的2倍 两者是相遇的地点meet 分别冲head 和 meet出发 两个指针速度一样 相遇为环的起点
// head -> start ==> a     start -> meet ==> b  meet -> start ==> c
// 2 * (a + b) = a + b + c + b   ===> b = c 

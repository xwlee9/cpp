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
    ListNode* partition(ListNode* head, int x) {
        ListNode less_head(0); 
        ListNode more_head(0);  // 设定两个临时的头节点
        ListNode* less_ptr = &less_head;
        ListNode* more_ptr = &more_head;  // 对应指针指向这两个头节点
        while (head)
        {
            if (head->val < x) 
            {
                less_ptr -> next = head;
                less_ptr = less_ptr -> next;
            }
            else 
            {
                more_ptr -> next = head;
                more_ptr = more_ptr->next;
            }
            head = head->next;
        }
        less_ptr -> next = more_head.next;
        more_ptr -> next = NULL;
        return less_head.next;
    }
};
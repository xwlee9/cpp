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
    ListNode* removeNthFromEnd(ListNode* head, int n) 
    {
        ListNode* fast = head;
        ListNode* slow = head;
        for(int i = 0; i < n; ++i) 
        {
            fast = fast -> next;
        }
        if (!fast)
        {
            if(n == 1) return fast;  // 链表长度为1 返回空
            else return slow -> next;  // 链表长度大于1 返回 slow-> next
        }
        while(fast -> next)
        {
            slow = slow -> next;
            fast = fast -> next;
        }
        ListNode* temp;
        temp = slow -> next;
        slow -> next = temp -> next;
        temp -> next = NULL;
        return head;
    }
};
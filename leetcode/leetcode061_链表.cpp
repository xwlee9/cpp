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
    ListNode* rotateRight(ListNode* head, int k) 
    {
        ListNode* fast = head;
        ListNode* slow = head;
        ListNode* temp = head;
        int count = 0;
        while (temp) 
        {
            temp = temp -> next;
            count ++;
        }
        if(count == 0) return head;
        k = k % count; 
        for(int i = 0; i < k; ++i) fast = fast -> next;
        while(fast -> next)
        {
            fast = fast -> next;
            slow = slow -> next;
        }
        fast -> next = head;
        ListNode* res = slow -> next;
        slow -> next = NULL;
        return res;
    }
};
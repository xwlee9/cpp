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
    ListNode* removeElements(ListNode* head, int val) 
    {
        ListNode* res = new ListNode(0);
        res -> next = head;
        ListNode* pre = res;
        while(pre -> next)
        {
            ListNode* temp = pre -> next;
            if (pre -> next -> val == val) 
            {
                pre -> next = temp -> next;
                continue;
            }
            else pre = temp;
        }
        return res -> next;
    }
};
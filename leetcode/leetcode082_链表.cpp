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
    ListNode* deleteDuplicates(ListNode* head) 
    {
        ListNode* res = new ListNode(0);
        ListNode* pre = res;
        pre -> next = head;
        int flag = 0;
        while (pre)
        {
            while (pre -> next && pre -> next -> next && pre -> next -> val == pre -> next -> next -> val) 
            {
                flag = 1;
                ListNode* temp = pre -> next -> next;
                pre -> next = temp;
            }
            if (flag == 1)
            {
                pre -> next = pre -> next -> next;
                flag = 0;
            }
            else
            {
               pre = pre -> next; 
            }
        }
        return res -> next;
    }
};
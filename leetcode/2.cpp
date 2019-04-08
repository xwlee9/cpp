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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
    {
        ListNode *a1 = new ListNode(0);
        ListNode *a = a1;
        int carry = 0;
        int num1;
        int num2;
        while(l1 || l2)
        {
            num1 = l1 ? l1->val : 0;
            num2 = l2 ? l2->val : 0;
            int add = num1 + num2 + carry;
            a->next = new ListNode(add % 10);
            carry = add / 10;
            a = a-> next;
            if (l1) l1 = l1->next;
            if (l2) l2 = l2->next;  
        }
        if (carry) a->next = new ListNode(1) ;
        return a1 -> next;
    }
};
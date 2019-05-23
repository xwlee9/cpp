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
        ListNode* res = head;
        while(head)
        {
            while (head && head -> next && head -> val == head -> next -> val) head -> next = head -> next -> next;
            head = head -> next;
        }
        return res;   
    }
};
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
    ListNode* swapPairs(ListNode* head) 
    {
        ListNode* node = head;
        ListNode* result;
        if (!node || !node -> next) return head;
        else {
            result = head -> next;
        }
        ListNode A(0);
        ListNode* Lnode = &A;  // 记录上一个节点
        while (node && node -> next)
        {
                ListNode* temp = node -> next;
                Lnode -> next = temp;
                node -> next = temp -> next;
                temp -> next = node;
                Lnode = node;
                node = node -> next;
        }
        return result;
    }
};
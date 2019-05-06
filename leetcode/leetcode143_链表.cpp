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
    void reorderList(ListNode* head) 
    {
        if(head == NULL || head -> next == NULL) return;
        ListNode* NewNode = NULL;
        ListNode* fast = head;
        ListNode* slow = head;
        while (fast -> next && fast -> next ->next)
        {
            slow = slow -> next;
            fast = fast -> next -> next;
        }
        ListNode* node = slow -> next;
        slow -> next = NULL;
        while (node -> next)
        {
            ListNode* temp = node -> next;  // 
            node -> next = NewNode;  // 1 => NULL 
            NewNode = node;  // 1
            node = temp;  // 2
        }
        node -> next = NewNode;
        ListNode* new_head = head;
        while (new_head && node)
        {
            ListNode* temp1 = node;
            node = node -> next;
            ListNode* temp2 = new_head -> next;  // 记录原本的下一节点
            temp1 -> next = temp2;  // node 下一节点 为 temp2
            new_head ->next = temp1;
    
            new_head = temp2;
        }
       
    }
};
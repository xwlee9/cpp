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
    ListNode* reverseKGroup(ListNode* head, int k) 
    {
        ListNode* res = new ListNode(0);
        ListNode* pre = res;
        ListNode* cur = pre;
        res -> next = head;
        int count = 0;
        while (cur -> next)
        {
            cur = cur -> next;
            count ++;
        }
        while (count >= k)
        {
            cur = pre -> next; 
            for (int i = 1; i < k; ++i)
            {
                ListNode* temp = cur -> next;
                cur -> next = temp -> next;
                temp -> next = pre -> next;   // 不用单独一个向量 用pre -> next 保存上一个节点
                pre -> next = temp;
            }
            pre = cur;
            count -= k;
        }
        return res -> next;
    }
};

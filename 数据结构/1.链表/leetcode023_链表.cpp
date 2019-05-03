#include <iostream>
#include <algorithm>
#include <vector>
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
// 使用vector
bool cmp(const ListNode* a,const ListNode* b)
{
    return a->val < b->val;
}

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) 
    {
        vector<ListNode*> node_vec;
        for (int i = 0; i < lists.size(); ++i)
        {
            ListNode* head = lists[i];
            while (head)
            {
                node_vec.push_back(head);
                head = head -> next;
            } 
        }
            if (node_vec.size() == 0) return NULL;
            sort (node_vec.begin(),node_vec.end(),cmp);  // 排序
            for (int i = 0; i < node_vec.size()-1; ++i)
            {
                node_vec[i] -> next = node_vec[i+1];
            }
        node_vec[node_vec.size()-1] -> next = NULL;
        return node_vec[0];
    }
};

// ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) 
// {
//     ListNode head(0);
//     ListNode *ptr = &head;
//     while(l1 && l2)
//     {
//         if(l1->val > l2->val)
//         {
//             ptr -> next = l2;
//             l2 = l2 -> next;
//         }
//         else
//         {
//             ptr -> next = l1;
//             l1 = l1 -> next;               
//         }
//         ptr = ptr -> next;
//             }
//     if (l1) ptr->next = l1;
//     if (l2) ptr->next = l2;
//     return head.next;
// }
// class Solution {
// public:
//     ListNode* mergeKLists(vector<ListNode*>& lists) 
//     {
//         if(lists.size() == 0) return NULL;
//         if(lists.size() == 1) return lists[0];
//         if(lists.size() == 2) return mergeTwoLists(lists[0],lists[1]);

//         int mid = lists.size()/2;
//         vector<ListNode*> sub1_lists;
//         vector<ListNode*> sub2_lists;
//         for (int i = 0; i< mid; ++i) sub1_lists.push_back(lists[i]);
//         for (int i = mid; i < lists.size(); ++i) sub2_lists.push_back(lists[i]);
//         ListNode* l1 = mergeKLists(sub1_lists);
//         ListNode* l2 = mergeKLists(sub2_lists);
        
//         return mergeTwoLists(l1,l2);
//     }
// };
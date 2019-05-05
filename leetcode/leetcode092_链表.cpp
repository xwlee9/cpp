#include <iostream>
using namespace std;

struct  ListNode
{
    int val;
    ListNode *next;
    ListNode(int x): val(x), next(NULL){}
};
/*
1. 找到开始开始逆置的节点 记录节点
2. 从head开始 逆置chaneg_len = n-m+1个节点
3. pre_head与new_head连接 modify_list_tail和head连接
*/
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
    ListNode* reverseBetween(ListNode* head, int m, int n) 
    {
        int change_len = n - m + 1;
        ListNode* pre_head = NULL;
        ListNode* result = head;
        while (head && --m) // 将head指针指向第m个位置
        {
            pre_head = head;
            head = head->next;
        }
        ListNode *modify_list_tail = head; // 当前head指向list_tail 翻转后就是链表尾 
        ListNode* new_head = NULL;      // 保存翻转后链表的下一地址 即翻转前的前一地址
        while (head && change_len)  // 此处反转链表
        {
            ListNode* next = head->next;   // 保存当前链表的下一地址
            head->next = new_head;   // 当前链表的下一地址指向前一地址
            new_head = head; // 下一步 当前地址取代前一地址
            head = next;  // 当前的下一地址取代 当前地址
            --change_len;
        }
        modify_list_tail->next = head;  // 第n+1地址指向翻转链表的尾部地址
        if (pre_head) pre_head->next =  new_head;  // 不为空 即不是第一个节点开始逆的
        else  result = new_head; // 为空  第一个节点开始的 及result指向反转后的第一个节点
        return result;

    }
};
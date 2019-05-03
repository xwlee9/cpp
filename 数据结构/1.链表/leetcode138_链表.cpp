#include <iostream>
#include <map>
#include <vector>
using namespace std;


// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node() {}

    Node(int _val, Node* _next, Node* _random) {
        val = _val;
        next = _next;
        random = _random;
    }
};

class Solution {
public:
    Node* copyRandomList(Node* head) 
    {
        map<Node*, int> node_map;
        vector<Node*> node_vec;  // 新链表用vector存储
        Node* ptr = head;
        int i = 0;
        while (ptr)
        {
            node_vec.push_back(new Node(ptr->val));
            node_map[ptr] = i; 
            ptr = ptr->next;
            ++i;
        }
        node_vec.push_back(0);
        ptr = head;
        i = 0;
        while (ptr) 
        {
            node_vec[i] -> next = node_vec[i+1];  // 连接新链表的next指针
            if (ptr->random) //random指针不是空的时候
            {
                int id = node_map[ptr->random];
                node_vec[i] -> random = node_vec[id];  // 将新链表的random指针指向对应位置
            }
            else  node_vec[i] -> random = NULL;
            ptr = ptr -> next;
            ++i;
        }
        return node_vec[0];
    }
};
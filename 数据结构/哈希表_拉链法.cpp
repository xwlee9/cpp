#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct ListNode
{
    int val;
    ListNode* next;
    ListNode (int x): val(x), next(NULL){}
};

int hash_func(int key, int table_len) 
{
    return key % table_len;  // 整数哈希 直接取余
}

void insert(ListNode* hash_table[], ListNode* node, int table_len)
{
    int hash_key = hash_func(node -> val, table_len);  
    node -> next = hash_table[hash_key]; // 头插法插入节点
    hash_table[hash_key] = node;
}

bool search(ListNode *hash_table[], int value, int table_len)
{
    int hash_key = hash_func(value, table_len);
    ListNode* head = hash_table[hash_key];
    while (head)
    {
        if (head -> val == value) return true;
        head = head -> next;
    }
    return false;
}

int main()
{
    const int TABLE_LEN = 11;
    ListNode* hash_table[TABLE_LEN] = {0};
    vector<ListNode*> hash_node_vec;
    int test[9] = {1,1,4,9,20,30,150,300,500};
    for (int i = 0; i < 8; ++i)  hash_node_vec.push_back(new ListNode(test[i]));
    for (int i = 0; i < hash_node_vec.size(); ++i) insert(hash_table, hash_node_vec[i], TABLE_LEN);
    cout << "HASH TABLE!" << endl; 
    for (int i = 0; i < TABLE_LEN; ++i)
    {
        cout << "[" << i << "]";
        ListNode* head = hash_table[i];
        while(head)
        {
            cout << " -> " << head ->val;
            head = head -> next;
        }
        cout << endl;
    }
    cout << "search : " << endl;
    for (int i = 0; i < 20; ++i)
    {
        if (search(hash_table, i, TABLE_LEN)) cout << i << "  is in the table!!!" << endl;
        else cout << i << "  is not in the table!!!" <<endl;
    }
    return 0;
}
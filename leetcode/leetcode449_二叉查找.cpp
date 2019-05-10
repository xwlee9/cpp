#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) 
    { 
        string data;
        BST_preorder(root,data);
        return data;   
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) 
    {
        if (data.length() == 0) return NULL;
        vector <TreeNode*> node_vec;
        int val = 0;
        for (int i = 0; i < data.length(); ++i)
        {
            if (data[i] == '#')
            {
                node_vec.push_back(new TreeNode(val));
                val = 0;
            }
            if ('0' <= data[i] && '9' >= data[i])
            {
                val = val * 10 + data[i] - '0';  
            }
        }
        for (int i = 1; i < node_vec.size(); ++i)
        {
            BST_insert(node_vec[0], node_vec[i]);
        }
        return node_vec[0];   
    }
private:
    void change_int_2_string(int val, string& str_val)
    {
        string temp;
        while(val)
        {
            temp += (val % 10) + '0';
            val = val / 10;
        }
        for (int i = temp.length() - 1; i >= 0; --i) str_val += temp[i];
        str_val += '#';
    }
    void BST_preorder(TreeNode* node, string& data)
    {
        if (!node)  return;
        string str_val; //临时接每个节点的数字
        change_int_2_string(node->val, str_val);
        data += str_val; 
        BST_preorder(node->left, data);
        BST_preorder(node->right, data);
    }
    void BST_insert(TreeNode* node, TreeNode* insert_node)
    {
        if (node -> val > insert_node -> val)
        {
            if (node -> left) BST_insert(node -> left, insert_node);
            else  node -> left = insert_node;
        }
        else 
        {
            if (node -> right)  BST_insert(node -> right, insert_node);
            else  node -> right = insert_node;
        }
    }
};

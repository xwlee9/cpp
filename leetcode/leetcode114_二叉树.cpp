#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
#include <string>
#include <time.h>
using namespace std;

//  Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// // 利用vector 来存储
// class Solution 
// {
// public:
//     void flatten(TreeNode* root) 
//     {
//         vector<TreeNode*> node_vec;
//         generate(root, node_vec);
//         for(int i = 1; i < node_vec.size(); ++i)
//         {
//             node_vec[i-1] -> right = node_vec[i];
//             node_vec[i-1] -> left = NULL; 
//         }        
//     }
// private:
//     void generate(TreeNode *node, vector<TreeNode*> &node_vec)
//     {
//         if (!node) return;
//         node_vec.push_back(node);
//         generate(node -> left, node_vec);
//         generate(node -> right, node_vec);
//     }
// };

// // 原地遍历

class Solution 
{
public:
    void flatten(TreeNode* root) 
    {
        TreeNode* last = NULL;
        generate(root, last);        
    }
    void generate(TreeNode* node, TreeNode* &last)
    {
        if(!node) return;
        if (!node->left && !node->right)   // 判断是叶子节点    last ==> 本身
        {
            last = node;
            return;
        }
        TreeNode* left = node -> left;  // 保存原本的节点
        TreeNode* right = node -> right;
        TreeNode* left_last = NULL;
        TreeNode* right_last = NULL;
        if (left)   // 左子树不空
        {
            generate(left, left_last);
            node -> left = NULL;   // 当前节点的左子节点指向空
            node -> right = left;   // 右子节点为left 
            last = left_last;
        } 
        if (right)  // 右子树不空
        {
            generate(right, right_last);   // 传的引用 会修改right_last
            if (left_last) left_last -> right = right;  // 如果有左子树 左子树的最有一个节点接当前right
            last = right_last;  // right_last得到修改 
        }
    }
};
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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// 公共祖先 一定在根节点到两个节点到路径上  距离他们最近到相同节点
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q)
    
    {
        vector<TreeNode*> result1;
        vector<TreeNode*> result2;
        vector<TreeNode*> path;
        int finish = 0;
        generate(root, p, path, result1, finish);
        finish = 0;
        path.clear();
        generate(root, q, path, result2, finish);
        int i = 0;
        int l1 = result1.size();
        int l2 = result2.size();
        while(result1[i] == result2[i]) 
        {
            ++i;
            if (i >= l1 || i >= l2)  break; // ++i > l2-1 或者 l1-1
        }
        return result1[i-1];
    }
    void generate(TreeNode* node, TreeNode* search, vector<TreeNode*>& path, vector<TreeNode*>& result, int& finish)
    {
        if (!node || finish == 1) return;
        path.push_back (node);
        if (node == search) 
        {
            finish = 1;
            result = path;
        }
        generate(node->left, search, path, result, finish);
        generate(node->right, search, path, result, finish);
        path.pop_back();
    }
};
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) 
    {
        
        vector<int> res;
        fun(root, res);
        return res;
    }
    void fun(TreeNode* root, vector<int>& res)
    {
        if (!root) return;
        fun(root -> left,res);
        res.push_back(root -> val);
        fun(root -> right,res);
    }
};
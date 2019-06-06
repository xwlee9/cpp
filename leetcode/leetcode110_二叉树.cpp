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
    bool isBalanced(TreeNode* root) 
    {
        if (!root) return true;
        if (abs(fun(root -> left) - fun(root -> right)) > 1) return false;
        return isBalanced(root -> left) && isBalanced(root -> right);
    }
private:
    int fun(TreeNode* root)
    {
        if (!root) return 0;
        return 1 + max(fun(root -> left), fun(root -> right));
    }
};
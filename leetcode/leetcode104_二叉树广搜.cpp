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
    int maxDepth(TreeNode* root) 
    {
        queue<pair<TreeNode*,int> > q;
        int max = 0;
        if (root)  q.push(make_pair(root,1));
        else return 0;
        while (!q.empty())
        {
            TreeNode* node = q.front().first;
            int d = q.front().second;
            q.pop();
            if (max < d)  max = d;
            if (node -> left) q.push(make_pair(node -> left, d+1));
            if (node -> right) q.push(make_pair(node -> right, d+1));
        }
        return max;        
    }
};
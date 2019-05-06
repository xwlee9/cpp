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
class Solution {
public:
    bool hasPathSum(TreeNode* root, int sum)
    {
        vector<int> path;
        int path_value = 0;
        bool flag = false;
        generate(root, path_value, sum, path, flag);
        return flag;
    }
private:
    void generate(TreeNode* node, int& path_value, int sum, vector<int> &path, bool& flag)
    {
        if (!node) return;
        path_value += node->val;
        path.push_back(node->val);
        if (path_value == sum && !node->left && !node->right) 
        {
            flag = true;
            return;  
        };
        generate(node->left, path_value, sum, path, flag); 
        generate(node->right, path_value, sum, path, flag);
        path_value -= node->val;
        path.pop_back();
    }
};
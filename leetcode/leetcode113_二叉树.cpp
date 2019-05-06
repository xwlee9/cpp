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

class Solution {
public:
    vector<vector<int> > pathSum(TreeNode* root, int sum) 
    {
        vector< vector<int> > result;
        vector<int> path;
        int path_value = 0;
        generate(root, path_value, sum, result, path);
        return result;
    }
private:
    void generate(TreeNode* node, int& path_value, int sum, vector< vector<int> > &result, vector<int> &path)
    {
        if (!node) return;
        path_value += node->val;
        path.push_back(node->val);
        if (path_value == sum && !node->left && !node->right) result.push_back(path);  // 保证到头 
        generate(node->left, path_value, sum, result, path); 
        generate(node->right, path_value, sum, result, path);
        path_value -= node->val;  // 回退 
        path.pop_back();
    }
};
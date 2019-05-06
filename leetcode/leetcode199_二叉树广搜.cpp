#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
#include <string>
#include <time.h>
#include <queue>
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
    vector<int> rightSideView(TreeNode* root) 
    {
        queue < pair<TreeNode*, int> > q;
        vector<int> result;
        if (root) q.push(make_pair(root,0));
        while (!q.empty())
        {
            TreeNode* node = q.front().first;
            int depth = q.front().second;
            q.pop();
            if (result.size() == depth) result.push_back(node -> val);
            else  result[depth] = node -> val;
            if (node -> left) q.push(make_pair(node -> left, depth+1)); 
            if (node -> right) q.push(make_pair(node -> right, depth+1));
        } 
        return result;     
    }
};
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
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

void BFS_print (TreeNode* root)
{
    queue<TreeNode*> Q;
    Q.push(root);
    while(!Q.empty())
    {
        TreeNode *node = Q.front();
        Q.pop();
        cout << "[" << node->val <<  "]" << endl;
        if (node -> left) Q.push(node -> left);
        if (node -> right) Q.push(node -> right);
    }
}
int main()
{
    TreeNode a(1);
    TreeNode b(2);
    TreeNode c(3);
    TreeNode d(4);
    TreeNode e(5);
    TreeNode f(6);
    a.left = &b;
    a.right = &c;
    b.left = &d;
    b.right = &e;
    c.left = &f;
    BFS_print(&a);
    return 0;
}

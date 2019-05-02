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

void BST_insert(TreeNode* node, TreeNode* insert_node)
{
    if(insert_node -> val < node -> val )
    {
        if(node -> left)  BST_insert(node -> left, insert_node);
        else  node -> left = insert_node;
    }
    else
    {
        if(node -> right) BST_insert(node -> right, insert_node);
        else  node -> right = insert_node;
    }
}

void preorder_print(TreeNode* node, int layer)
{
    if(!node) return;
    for (int i = 0; i < layer; ++i)  cout << "----";
    cout << "[" << node -> val << "]" << endl;
    preorder_print(node->left, layer + 1);
    preorder_print(node->right, layer + 1);
}

bool BST_search (TreeNode* node, int value)
{
    if (value == node -> val) return true;
    if (value < node -> val)  // 左子树
    {
        if (node -> left) return BST_search(node -> left, value);
        else return false;
    }
    else   // 右子树
    {
        if (node -> right) return BST_search(node -> right, value);
        else return false;
    }
}

int main()
{
    TreeNode root(8);
    vector<TreeNode*> node_vec;
    int test[] = {1, 2, 10, 17, 3, 22, 7, 9};
    for (int i = 0; i < 8; ++i) node_vec.push_back(new TreeNode(test[i]));
    for (int i = 0; i < 8; ++i) BST_insert(&root, node_vec[i]);
    preorder_print(&root, 0);
    for (int i = 0; i < 25; ++i)
    {
        if (BST_search(&root,i)) cout << i << ": exist!!!" << endl;
        else  cout << i << ": not exist!!!" << endl;
    }
    for (int i = 0; i < 8; ++i) delete node_vec[i];
    return 0;

}
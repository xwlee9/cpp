#include<iostream>
#include<vector>
#include<string>
#define TRIE_MAX_CHAR_NUM 26
using namespace std;

struct TrieNode
{
    TrieNode* child[TRIE_MAX_CHAR_NUM];
    bool is_end;
    TrieNode() : is_end(false)
    {
        for (int i = 0; i < TRIE_MAX_CHAR_NUM; ++i) child[i] = 0;
    }
};

// void preorder_trie(TrieNode* node, int layer)
// {
//     for (int i = 0; i < TRIE_MAX_CHAR_NUM; ++i)
//     {
//         if (node -> child[i])
//         {
//             for (int j = 0; j < layer; ++j) cout << "---";
//             cout << i + 'a';
//             if (node -> child[i] -> is_end) cout << "<end>";
//             cout << endl;
//             preorder_trie(node -> child[i], layer + 1);
//         }
//     }
// }

/*        */
// void get_all_word(TrieNode* node, string& word, vector<string>& word_list)
// {
//     for(int i = 0; i < TRIE_MAX_CHAR_NUM; ++i)
//     {
//         if (node -> child[i])
//         {
//             word.push_back('a' + i);
//             if (node -> child[i] -> is_end) word_list.push_back(word);
//             get_all_word(node -> child[i], word, word_list);
//             word.erase(word.length()-1, 1);
//         }
//     }
// }


class TrieTree
{
public:
    TrieTree(){}
    ~TrieTree()
    {
        for(int i = 0; i < _node_vec.size(); i++) delete _node_vec[i];
    }
    void insert(const char* word)
    {
        TrieNode* ptr = &_root;
         while(*word)
        {
            int pos = *word - 'a';
            if (!ptr -> child[pos])  ptr -> child[pos] = new_node();
            ptr = ptr -> child[pos];
            word++;
        }
        ptr -> is_end = true;
    }

    bool search(const char* word)
    {
        TrieNode* ptr = &_root;
        while(*word)
        {
            int pos = *word - 'a';
            if (!ptr -> child[pos]) return false;;
            ptr = ptr -> child[pos];
            word++;
        }
        return ptr -> is_end; 
    }

    bool prefix(const char* pre)
    {
        TrieNode* ptr = &_root;
        while(*pre)
        {
            int pos = *pre - 'a';
            if (!ptr -> child[pos]) return false;
            ptr = ptr -> child[pos];
            pre++;
        }
        return true;
    }
private:
    TrieNode* new_node()
    {
        TrieNode* node = new TrieNode();
        _node_vec.push_back(node);
        return node;
    }
    vector<TrieNode*> _node_vec;
    TrieNode _root;
};

int main()
{
    TrieTree tree;
    tree.insert("abcd");
    tree.insert("abc");
    tree.insert("abd");
    tree.insert("bcd");
    tree.insert("efg");
    tree.insert("agh");
    cout << tree.search("abc") << endl;
    cout << tree.search("agh") << endl;
    cout << tree.search("a") << endl;
    cout << tree.prefix("ab") << endl;
    cout << tree.prefix("ef") << endl;
    return 0;
}
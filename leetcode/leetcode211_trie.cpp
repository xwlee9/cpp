#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct TrieNode
{
    TrieNode* child[26];
    bool is_end;
    TrieNode() : is_end(false)
    {
        for (int i = 0; i < 26; ++i) child[i] = 0;
    }
};


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

    bool search(const char* word, TrieNode* node)
    {
        // TrieNode* ptr = &_root;
        if (*word == '\0') return node -> is_end;
        if (*word == '.') 
        {
            for (int i = 0; i < 26; ++i)
            {
                if (node -> child[i] && search(word+1, node -> child[i])) return true;
            }
        }
        else
        {
            int pos = *word - 'a';
            if (node -> child[pos] && search(word+1, node -> child[pos])) return true;
        }
        return false;
    }
    TrieNode* root()
    {
        return &_root;
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


class WordDictionary {
public:
    /** Initialize your data structure here. */
    WordDictionary() {
        
    }
    
    /** Adds a word into the data structure. */
    void addWord(string word) 
    {
        _trie_tree.insert(word.c_str());
    }
    
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) 
    {
        return _trie_tree.search(word.c_str(),_trie_tree.root());
    }
private:
    TrieTree _trie_tree;
};
/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */


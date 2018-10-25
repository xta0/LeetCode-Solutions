#include <iostream>
#include <vector>
#include <string>
#include <array>
using namespace std;

struct TrieNode{
    bool isEnd = false;
    array<TrieNode*,26> children = {nullptr};
    char c = ' ';
    TrieNode(char key):c(key){}
};

class Trie {
    TrieNode* root;
public:
    /** Initialize your data structure here. */
    Trie() {
        root = new TrieNode('*');
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        TrieNode* node = root;
        for(int i =0; i<word.size(); i++){
            char c = word[i];
            int index = c-'a';
            TrieNode* n = node->children[index];
            if(!n){
                node->children[index] = new TrieNode(c);
                node = node->children[index];
            }else{
                node = n;
            }
        }
        node->isEnd = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        
        TrieNode* node  = root;
        int index = 0;
        for(int i=0;i<word.size();i++){
            char c = word[i];
            index = c-'a';
            TrieNode* n = node->children[index];
            if(!n || n->c != c){
                return false;
            }else{
                node = n;
            }
        }
        return node->isEnd;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        int index = 0;
        TrieNode* node = root;
        for(int i=0;i<prefix.size();i++){
            char c = prefix[i];
            index = c-'a';
            TrieNode* n = node->children[index];
            if(!n || n->c != c){
                return false;
            }else{
                node = n;
            }
        }
        return true;
    }
};

int main(){
    
    Trie* trie = new Trie();
    trie->insert("apple");
    cout<<trie->search("apple")<<endl;   // returns true
    cout<<trie->search("app")<<endl;     // returns false
    cout<<trie->startsWith("app")<<endl; // returns true
    trie->insert("app");
    cout<<trie->search("app")<<endl;     // returns true
    
    return 0;
}

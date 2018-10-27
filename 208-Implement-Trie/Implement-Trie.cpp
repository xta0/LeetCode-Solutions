#include <iostream>
#include <vector>
#include <string>
#include <array>
using namespace std;

struct TrieNode{
    bool isEnd = false;
    array<TrieNode*,26> children = {nullptr};
    ~TrieNode(){
        cout<<"dealloc"<<endl;
        for(auto& x:children){
            delete x;
            x = nullptr;
        }
    }
};

class Trie {
    TrieNode* root;
public:
    /** Initialize your data structure here. */
    Trie() {
        root = new TrieNode();
    }
    ~Trie(){
        delete root;
        root = nullptr;
    }
    /** Inserts a word into the trie. */
    void insert(string word) {
        TrieNode* node = root;
        for(int i =0; i<word.size(); i++){
            int index = word[i]-'a';
            TrieNode* n = node->children[index];
            if(!n){
                node->children[index] = new TrieNode();
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
        for(int i=0;i<word.size();i++){
            int index = word[i]-'a';
            TrieNode* n = node->children[index];
            if(!n){
                return false;
            }else{
                node = n;
            }
        }
        return node->isEnd;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        TrieNode* node = root;
        for(int i=0;i<prefix.size();i++){
            int index = prefix[i]-'a';
            TrieNode* n = node->children[index];
            if(!n){
                return false;
            }else{
                node = n;
            }
        }
        return true;
    }
};

int main(){
    
    Trie trie = Trie();
    trie.insert("apple");
    cout<<trie.search("apple")<<endl;   // returns true
    cout<<trie.search("app")<<endl;     // returns false
    cout<<trie.startsWith("app")<<endl; // returns true
    trie.insert("app");
    cout<<trie.search("app")<<endl;     // returns true
    
    return 0;
}

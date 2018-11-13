#include <iostream>
#include <vector>
#include <array>
#include <string>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <unordered_set>
#include <unordered_map>
using namespace std;

//构造trie树
struct TrieNode{
    bool isEnd;
    array<TrieNode*,26> children = {nullptr};
};
class Trie{
    TrieNode* _root;
public:
    Trie(){
        _root=new TrieNode();
    }
    void addWord(const string& word){
        TrieNode* root =  _root;
        for(auto c : word){
            int index = c-'a';
            if(root->children[index] == nullptr){
                root->children[index] = new TrieNode();
            }
            root = root->children[index];
        }
        root->isEnd = true;
    }
    TrieNode* get_root() const{
        return _root;
    }
};

class Solution {
    void dfs(vector<vector<char>>& board, int i, int j, int w, int h, vector<vector<bool>>& marks, string chosen, TrieNode* node, unordered_set<string>& us){

        if(i<0 || i>=h || j>=w || j<0){
            return ;
        }
        if(marks[i][j]){
            return ;
        }
        char c = board[i][j];
        chosen += c;
        TrieNode* child = node->children[c-'a'];
        if(!child){
            return;
        }else{
            if(child->isEnd){
                us.insert(chosen);
            }
            node = child;
        }

        marks[i][j] = true;
        dfs(board,i,j+1,w,h,marks,chosen,node,us);
        dfs(board,i+1,j,w,h,marks,chosen,node,us);
        dfs(board,i,j-1,w,h,marks,chosen,node,us);
        dfs(board,i-1,j,w,h,marks,chosen,node,us);
        marks[i][j] = false;
    }
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        size_t h = board.size();
        if(h==0)return {};
        size_t w = board[0].size();
        if(w==0)return {};
        Trie* trie = new Trie();
        for(auto& word: words){
            trie->addWord(word);
        }
        vector<vector<bool>> marks(h,vector<bool>(w,false));
        unordered_set<string> us;
        for(int i=0;i<h;i++){
            for(int j=0;j<w;j++){
                dfs(board,i,j,(int)w,(int)h,marks,"",trie->get_root(),us);
            }
        }
        return {us.begin(),us.end()};
    }
};


int main(){
    vector<string> words = {"aba","baa","bab","aaab","aaa","aaaa","aaba"};
    vector<vector<char>> boards = {{'a','b'},{'a','a'}};
    Solution s;
    auto v = s.findWords(boards,words);
    for(auto s:v){
        cout<<s<<endl;
    }
    
    
    
    return 0;
}

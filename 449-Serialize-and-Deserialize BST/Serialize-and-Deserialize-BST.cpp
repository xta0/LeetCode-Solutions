//
//  main.cpp
//  Playground3
//
//  Created by moxin on 11/4/18.
//  Copyright © 2018 Tao Xu. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

 
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };
 
class Codec {
public:
    void dfs(TreeNode* root,string& s){
        if(!root){
            return ;
        }
        string str = to_string(root->val) + " ";
        s+=str;
        dfs(root->left,s);
        dfs(root->right,s);
        
    }
    void constructBST(TreeNode* root, int val){
        if(!root){
            return;
        }
        if(val < root->val){
            if(!root->left){
                root->left = new TreeNode(val);
            }else{
                constructBST(root->left,val);
            }
        }else{
            if(!root->right){
                root->right = new TreeNode(val);
            }else{
                constructBST(root->right, val);
            }
        }
        
    }
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        
        string s = "";
        dfs(root,s);
        return s;
    }
    
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.size() == 0){
            return nullptr;
        }
        vector<string> nodes;
        int l = 0;
        int r = 0;
        while(r < data.size()){
            if(data[r] == ' '){
                nodes.push_back(data.substr(l,r-l));
                r++;
                l = r;
            }
            r++;
        }
        
        int rval = stoi(nodes[0]);
        TreeNode* root = new TreeNode(rval);
        
        for(int i=1;i<nodes.size();i++){
            int v = stoi(nodes[i]);
            constructBST(root,v);
        }
        return root;
        
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));

int main(int argc, const char * argv[]) {
    // insert code here...
    Codec code;
    TreeNode* root = new TreeNode(2);
    root->left = new TreeNode(1);
    root->right = new TreeNode(3);
    auto s = code.serialize(root);
    code.deserialize(s);
    return 0;
}

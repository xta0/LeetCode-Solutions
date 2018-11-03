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

class Solution {
public:
    //dfs search
    void dfs(TreeNode* root, TreeNode* p, TreeNode* &successor, bool& b){
        if(!root){
            return;
        }
        dfs(root->left,p,successor,b);
        if(b){
            if(!successor){
                successor = root;
            }
            return ;
        }
        if(root->val == p->val){
            b = true;
        }
        dfs(root->right,p,successor,b);
    
    }
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        if(!root || !p){
            return nullptr;
        }
        
        TreeNode* successor = nullptr;
        bool b = false;
        dfs(root,p,successor,b);
        
        return successor;
    }
};

int main(){
    Solution s;
    TreeNode* root = new TreeNode(2);
//    root->left = new TreeNode(3);
    root->right = new TreeNode(3);
    cout<<s.inorderSuccessor(root, new TreeNode(2))->val<<endl;
//    TreeNode* root = new TreeNode(5);
//    root->left = new TreeNode(3);
//    root->right = new TreeNode(6);
//    root->left->left = new TreeNode(2);
//    root->left->right = new TreeNode(4);
//    root->left->left->left = new TreeNode(1);
//    cout<<s.inorderSuccessor(root, new TreeNode(1))->val<<endl;
    return 0;
}

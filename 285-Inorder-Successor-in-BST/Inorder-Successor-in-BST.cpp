#include <iostream>
#include <vector>
#include <string>
using namespace std;
struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class Solution {
public:
    TreeNode* search(TreeNode* root, TreeNode* target, TreeNode*& rroot){
        if(!root){
            return NULL;
        }
        if(target->val < root->val){
            if(root->left == target){
                return root;
            }else{
                return search(root->left,target,rroot);
            }
        }else{
            if(root->right == target){
                return rroot;
            }else{
                return search(root->right,target,rroot);
            }
        }
        
    }
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
            TreeNode* rroot = root;
            return search(root,p,rroot);
    };
};

int main(){
    
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(1);
    root->right = new TreeNode(4);
    root->left->right = new TreeNode(2);
    
    Solution s;
    cout<<s.kthSmallest(root, 1)<<endl;
    
    return 0;
}

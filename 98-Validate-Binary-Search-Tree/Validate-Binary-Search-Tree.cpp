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
    bool isValidBST(TreeNode* root) {
        if(!root){
            return false;
        }
        if(!root->left && !root->right){
            return true;
        }
        
        bool bl = false, br=false;
        if(root->left){
            bl = root->val > root->left->val;
        }
        if(root->right){
            br = root->val < root->right->val;
        }
        if(bl && br){
            return isValidBST(root->left) && isValidBST(root->right);
        }else{
            return false;
        } 
    }
};  

int main(){

    TreeNode* root = new TreeNode(10);
    root->left = new TreeNode(5);
    root->right = new TreeNode(15);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(20);
    Solution s;
    cout<<s.isValidBST(root)<<endl;


    return 0;
}
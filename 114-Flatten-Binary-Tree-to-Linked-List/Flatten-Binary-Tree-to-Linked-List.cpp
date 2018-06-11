#include <iostream>
#include <stack>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

//post-order 后序遍历
/*
     1                  1                       1
    / \                / \                       \
   2   5   --->       2   5         ---->         2
  / \   \              \   \                       \
 3   4   6              3   6                       3
                         \                           \
                          4                           4
                                                       \
                                                        5
                                                         \
                                                          6
 */
class Solution {
public:
    void flatten(TreeNode* root) {
        if(!root){
            return ;
        }
        if(root->left){
            flatten(root->left);
        }
        if(root->right){
            flatten(root->right);
        }
        
        
        if(root->left || root->right){
            TreeNode* left = root->left ?: nullptr;
            TreeNode* right = root->right ?: nullptr;
            if(left){
                root->left = nullptr;
                root->right = left;
                while (left->right) {
                    left = left->right;
                }
                left->right = right;
            }
        }
        
    }
};



int main(){
    
    Solution s;
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->right = new TreeNode(5);
    root->right->right = new TreeNode(6);
    s.flatten(root);

    
    return 0;
}

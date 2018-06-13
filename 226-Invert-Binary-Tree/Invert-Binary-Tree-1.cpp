#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

//Invert recursively
//dfs : preorder traversal
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if(!root){
            return nullptr;
        }
        if(!root->left && !root->right){
            return root;
        }
        //preorder traversal, access the root first
        if(root->left || root -> right){
            swap(root->left , root->right);
        }
        invertTree(root->left);
        invertTree(root->right);
        return root;
    }
};
int main(){




    return 0;
}
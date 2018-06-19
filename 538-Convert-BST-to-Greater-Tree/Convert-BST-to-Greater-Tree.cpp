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
    TreeNode* convertBST(TreeNode* root) {
        if(!root){
            return nullptr;
        }
        if(!root->left && !root->right){
            return root;
        }

        if(root->left){
            root->left->val += (root->val + ( root->right?root->right->val : 0) );
        }
        if(root->right){
            root->val += root->right->val;
        }
        root->left = convertBST(root->left);
        root->right = convertBST(root->right);
        return root;
    }
};

int main(){




    return 0;
}
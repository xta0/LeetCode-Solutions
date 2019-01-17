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

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root){
            return root;
        }
        if(root == p || root == q){
            return root;
        }
        TreeNode* left = lowestCommonAncestor(root->left,p,q);
        TreeNode* right = lowestCommonAncestor(root->right,p,q);
        
        if(left && right){
            return root;
        }

        /*
            #
           / \
          #  #
            /|
           @ --> right (no need to continue to search )
          /|
         #  #
            /
            @ -->left
        */
        if(!left){
            return right;
        }
        if(!right){
            return left;
        }
        return nullptr;
    }
};

int main(){




    return 0;
}
#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution
{
  public:
    void helper(TreeNode *root, int val){
        if (root->val == val){
            return;
        }else if (val < root->val){
            if (!root->left){
                root->left = new TreeNode(val);
            }
            else{
                return helper(root->left, val);
            }
        }else{
            if (!root->right){
                root->right = new TreeNode(val);
            }
            else{
                return helper(root->right, val);
            }
        }
    }
    TreeNode *insertIntoBST(TreeNode *root, int val){
        if (!root){
            return nullptr;
        }
        helper(root,val);
        return root;
    }
};
int main()
{

    return 0;
}
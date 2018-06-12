#include <iostream>
#include <stack>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
//using stack
class Solution {
public:
    bool hasPathSum(TreeNode* root, int sum) {
        if(!root){
            return false;
        }
        int acc = 0;
        stack<TreeNode* >stk;
        stk.push(root);
        while(!stk.empty()){
            TreeNode* node = stk.top();
            stk.pop();
            acc+=node->val;
            if(!node->left && !node->right){
                if(acc == sum){
                    return true;
                }else{
                    acc -= node->val;
                }
            }
            if(node->right){
                stk.push(node->right);
            }
            if(node->left){
                stk.push(node->left);
            }
        }
        return false;
    }
};

int main(){
    




    return 0;
}
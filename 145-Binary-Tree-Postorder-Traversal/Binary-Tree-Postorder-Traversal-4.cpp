#include <iostream>
#include <vector>
#include <string>
#include <stack>

using namespace std;

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
/*

用栈来模拟Reverse PostOrder
rev_postorder(root){
    if(!root) return;
    print(root->val);
    //先右边
    rev_postOrder(root->right);
    //后左边
    rev_postOrder(root->left);
}    
*/

class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        if(!root){
            return {};
        }
        vector<int> res;
        stack<TreeNode* > stk;
        stk.push(root);
        while(!stk.empty()){
            TreeNode* node = stk.top();
            stk.pop();
            res.push_back(node->val);
            if(node->left){
                stk.push(node->left);
            }
            //右子树后入栈
            if(node->right){
                stk.push(node->right);
            }
        }
        return {res.rbegin(),res.rend()};
    }
};
int main(){




    return 0;
}
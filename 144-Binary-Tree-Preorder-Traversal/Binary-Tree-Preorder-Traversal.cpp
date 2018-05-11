#include <iostream>
#include <stack>
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
    vector<int> preorderTraversal(TreeNode* root) {
        if(!root){
            return {};
        }
        vector<int> ret;
        stack<TreeNode* > ss;
        ss.push(root);
        while(!ss.empty()){
            TreeNode* top = ss.top();
            ss.pop();
            ret.push_back(top->val);
            if(top->right){
                ss.push(top->right);
            }
            if(top->left){
                ss.push(top->left);
            }
        }
        return ret;
    }
};

int main(){
    return 0;
}
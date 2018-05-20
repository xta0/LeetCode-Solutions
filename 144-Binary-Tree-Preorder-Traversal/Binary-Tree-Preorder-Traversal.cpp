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
private:
    void visitAlongTheLeftBranch(TreeNode* root, stack<TreeNode* >& stc, vector<int>& vec){
        while(root){
            vec.push_back(root->val);
            if(root->right){
                stc.push(root->right);
            }
            root = root->left;
        }
    }
public:
    vector<int> preorderTraversal(TreeNode* root) {
        if(!root){
            return {};
        }
        vector<int> ret;
        stack<TreeNode* > ss;
        while(true){
            visitAlongTheLeftBranch(root,ss,ret);
            if(ss.empty()){
                break;
            }
            TreeNode* top = ss.top();
            ss.pop();
            root = top;
        } 
        return ret;
    }
};

int main(){
    return 0;
}
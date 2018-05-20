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
    void goAlongLeftBranch(TreeNode* root, stack<TreeNode* >& st){
        while(root){
            st.push(root);
            root = root->left;
        }
    }
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ret;
        stack<TreeNode*> st;
        while(true){
            goAlongLeftBranch(root,st);
            if(st.empty()){
                break;
            }
            TreeNode* top = st.top();
            st.pop();
            ret.push_back(top->val);
            if(top->right){
                root = top->right;
            }else{
                root = NULL;
            }
        }
        
        return ret;
    }
};

int main(){




    return 0;
}
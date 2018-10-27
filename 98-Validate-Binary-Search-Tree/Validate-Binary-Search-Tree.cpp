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

//中序遍历验证
class Solution {
public:
    void dfs(TreeNode* root, TreeNode* &last, bool& result){
        if(!root){
            return;
        }
        if(!result){
            return;
        }
        dfs(root->left,last,result);
        if(last && root->val <= last->val){
            result = false;
            return;
        }
        last = root;
        dfs(root->right,last,result);
    }
    bool isValidBST(TreeNode* root) {
        if(!root){
            return true;
        }
        if(!root->left && !root->right){
            return true;
        }
        bool result = true;
        TreeNode* last= nullptr;
        dfs(root,last,result);
        return result;
    }
};


int main(){
    
    TreeNode* root = new TreeNode(10);
    root->left = new TreeNode(10);
//    root->right = new TreeNode(15);
//    root->right->left = new TreeNode(6);
//    root->right->right = new TreeNode(20);
    Solution s;
    cout<<s.isValidBST(root)<<endl;
    
    
    return 0;
}

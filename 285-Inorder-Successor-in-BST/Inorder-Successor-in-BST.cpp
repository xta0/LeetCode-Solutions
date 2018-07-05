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
    TreeNode* dfs(TreeNode* root, TreeNode* p, bool& flag){
        if(!root){
            return NULL;
        }
        auto pl =  dfs(root->left,p,flag);
        if(pl){
            return pl;
        }else{
            if(flag){
                return root;
            }else{
                if(p->val==root->val){
                    flag = true;
                }
            }
        }
        auto pr = dfs(root->right,p,flag);
        if(pr){
            return pr;
        }else{
            return NULL;
        }
    }
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        bool flag = false;
        return dfs(root,p,flag);
    };
};

int main(){
    
    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(3);
    root->right = new TreeNode(6);
    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(4);
    root->left->left->left = new TreeNode(1);
    
    Solution s;
    TreeNode* p = new TreeNode(4);
    TreeNode* r = s.inorderSuccessor(root,p);
    if(r){
        cout<<r->val<<endl;
    }else{
        cout<<"NULL"<<endl;
    }
    // cout<<s.kthSmallest(root, 1)<<endl;
    
    return 0;
}

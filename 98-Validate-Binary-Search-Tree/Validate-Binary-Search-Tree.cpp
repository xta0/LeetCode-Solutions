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
    void dfs(TreeNode* root, vector<int>& arr){
        if(!root){
            return;
        }
        dfs(root->left,arr);
        arr.push_back(root->val);
        dfs(root->right,arr);
    }
public:
    bool isValidBST(TreeNode* root) {
        if(!root){
            return true;
        }
        if(!root->left && !root->right){
            return true;
        }
        vector<int> vec;
        dfs(root,vec);
        bool b = true;
        for(int i=0;i<vec.size();i++){
            if(i > 0){
                if(vec[i] <= vec[i-1]){
                    b = false;
                    break;
                }
            }
        }
        return b;
    }
};  

int main(){

    TreeNode* root = new TreeNode(10);
    root->left = new TreeNode(5);
    root->right = new TreeNode(15);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(20);
    Solution s;
    cout<<s.isValidBST(root)<<endl;


    return 0;
}
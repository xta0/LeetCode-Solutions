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
    void dfs(TreeNode* root, int& count, int k, int& result){
        if(!root){
            return;
        }
        dfs(root->left,count,k,result);
        count++;
        if(count == k){
            result = root->val;
            return;
        }
        dfs(root->right,count,k,result);
        
    }
    int kthSmallest(TreeNode* root, int k) {
        int count = 0;
        int result = -1;
        dfs(root,count,k,result);
        return result;
        
    }
};

int main(){
    
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(1);
    root->right = new TreeNode(4);
    root->left->right = new TreeNode(2);
    
    Solution s;
    cout<<s.kthSmallest(root, 1)<<endl;
    
    return 0;
}

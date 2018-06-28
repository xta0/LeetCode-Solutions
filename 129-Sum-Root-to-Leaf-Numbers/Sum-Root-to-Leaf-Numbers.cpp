#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    void dfs(TreeNode* root, int sum, int& total){
        if(!root){
            return ;
        }
        sum = sum*10 + root->val ;
        //check leaf
        if(!root->left && !root->right){
            total += sum;
            return;
        }
        
        //dfs
        dfs(root->left,sum,total);
        dfs(root->right,sum,total);
        
    }
    int sumNumbers(TreeNode* root) {
        int sum=0;
        int total = 0;
        dfs(root,sum, total);
        return total;
    }
};

int main(){
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    Solution s;
    cout<<s.sumNumbers(root)<<endl;
    
    
    
    return 0;
}

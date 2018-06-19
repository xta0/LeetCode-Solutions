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

void dfs(TreeNode* root, int& count){
    if(!root){
        return;
    }
    count ++;
    dfs(root->left,count);
    dfs(root->right,count);
    if(!root->left && !root->right){
        return ;
    }
    
}

class Solution {
public:
    int countNodes(TreeNode* root) {
        int count;
        dfs(root,count);
        return 
    }
};
    
int main(){




    return 0;
}
#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
/*
Solution: DFS
Time: O(N)
Space: O(N)
*/
class Solution {    
    void dfs(TreeNode* root, int target, int sum, bool& result){
        if(!root){
            return;
        }
        sum += root->val;
        /*
        check leaf node
        */
        if(!root->left && !root->right){
            if(sum == target){
                result = true;
            }
        }
        dfs(root->left,target,sum,result);
        dfs(root->right,target,sum,result);
        
    }
public:
    bool hasPathSum(TreeNode* root, int sum) {
        bool result = false;
        dfs(root,sum,0,result);
        return result;
    }
};

int main(){
    




    return 0;
}
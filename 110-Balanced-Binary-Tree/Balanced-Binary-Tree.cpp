#include <iostream>
#include <map>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

//DFS
//bottom-up solution
class Solution {
    int dfs(TreeNode* root){
        if(!root){
            return 0;
        }
        if(!root->left && !root->right){
            return 1;
        }
        //DFS down to the bottom
        int l = dfs(root->left);
        int r = dfs(root->right);
        //if l or r is -1, it means one of the substrees is imbalanced, then we can stop comparing(backtracking).
        if(l == -1 || r== -1){
            return -1;
        }else{
            //check if this substree is balanced.
            if(abs(l-r) > 1){
                return -1;//return -1 if it's imbalanced.
            }else{
                //if it's balanced, return the depth and continue backtracking.
                return max(l,r)+1;
            }
        }
    }
public:
    bool isBalanced(TreeNode* root) {      
        if(!root) {
            return true;
        }
        return dfs(root) != -1;
    }
};
int main(){




    return 0;
}
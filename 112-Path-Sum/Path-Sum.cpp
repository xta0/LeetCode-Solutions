#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
    //dfs + backtracking
    //dfs尽量不要设计返回值，很复杂，传入引用变量做判断条件
    void dfs(TreeNode* root, int& sum, int target, bool& found){
        if(!root){
            return;
        }
        sum += root->val;
        dfs(root->left,sum,target,found);
        dfs(root->right,sum,target,found);
    
        //检查叶节点位置
        if(!root->left && !root->right){
            if(sum == target){
                found =true;
                return;
            };
        }
        //backtracking
        sum -= root->val;
    }
public:
    bool hasPathSum(TreeNode* root, int sum) {
        if(!root){
            return false;
        }
        int acc = 0;bool found=false;
        dfs(root,acc, sum,found);
        return found;
    }
};

int main(){
    




    return 0;
}
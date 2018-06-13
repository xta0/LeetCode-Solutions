#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
//模板同112
class Solution {
    void dfs(TreeNode* root, int& acc, int sum, vector<int>& chosen, vector<vector<int>>& result){
        if(!root){
            return ;
        }
        acc+=root->val;
        chosen.push_back(root->val);
        dfs(root->left,acc,sum,chosen,result);
        dfs(root->right,acc,sum,chosen,result);
        
        
        //check leaf node
        if(!root->left && !root->right){
            if(sum == acc){
                result.push_back(chosen);
            }
        }
        //backtracking
        acc-=root->val;
        chosen.pop_back();
        
    }
public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        if(!root){
            return {};
        }
        int acc = 0;
        vector<int> chosen;
        vector<vector<int>> result;
        dfs(root,acc,sum,chosen, result);
        return result;
    }
};

int main(){




    return 0;
}
#include <iostream>
#include <vector>
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
public:
    void dfs(TreeNode* root, int target, int sum, vector<int>& path, vector<vector<int>>& result){
        if(!root){
            return;
        }
        
        sum += root->val;
        //choose
        path.push_back(root->val);
        /*
        check leaf node
        */
        if(!root->left && !root->right){
            if(sum == target){
                result.push_back(path);
            }
            //no return here!
        }
        dfs(root->left,target,sum,path,result);
        dfs(root->right,target,sum,path,result);
        //backtracking
        path.pop_back();   
        
    }
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> res;
        vector<int> path;
        dfs(root,sum,0,path,res);
        return res;
    }
};
int main(){




    return 0;
}
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <unordered_map>
using namespace std;

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    void search(TreeNode* root, double target, double diff, int& ans){
        if(!root){
            return;
        }
        double x = abs( (double)root->val - target );
        if(x<diff){
            ans = root->val;
            diff = x;
        }
        if(target < root->val){
            search(root->left,target,diff,ans);
        }else{
            search(root->right,target,diff,ans);
        }
    }
    int closestValue(TreeNode* root, double target) {
        int ans = 0;
        search(root,target,__DBL_MAX__,ans);
        return ans;
    }
};


int main(){
    Solution s;
    TreeNode* node = new TreeNode(1500000000);
    node->left = new TreeNode(1400000000);
    s.closestValue(node,-1500000000.0);
    
    
    
    return 0;
}

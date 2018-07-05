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
    void dfs(TreeNode* root, vector<int>& arr){
        if(!root){
            return;
        }
        dfs(root->left,arr);
        arr.push_back(root->val);
        dfs(root->right,arr);
    }
    bool findTarget(TreeNode* root, int k) {
        vector<int> arr;
        dfs(root,arr);
        int l = 0; int r = arr.size()-1;
        while(l < r){
            if((arr[l] + arr[r])<k){
                l++;
            }else if((arr[l] + arr[r]) > k){
                r--;
            }else{
                return true;
            }
        }
        return false;
    }
};

int main(){




    return 0;
}
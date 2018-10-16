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
    TreeNode* searchBST(TreeNode* root, int val) {
        if(!root){
            return nullptr;
        }
        if(root->val == val){
            return root;
        }
        else if(val < root->val){
            return searchBST(root->left,val);
        }
        else{
            return searchBST(root->right,val);
        }
    }
};
    

int main(){




    return 0;
}
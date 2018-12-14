#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <unordered_set>
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
    TreeNode* trimBST(TreeNode* root, int L, int R) {
        if(!root){
            return nullptr;
        }
        if(root->val >= L && root->val <= R){
            root->left = trimBST(root->left,L,R);
            root->right = trimBST(root->right,L,R);
            return root;
        }else if(root->val < L){
            //cut the left subtree & root
            return trimBST(root->right,L,R);
        }else{
            //cut right substree & root
            return trimBST(root->left,L,R);
        }
        
    }
};

int main(){




    return 0;
}
#include <iostream>
#include <queue>
#include <string>
#include <cmath>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

//模板同 #100
//递归比较
class Solution {
private:
    bool compare(TreeNode* root1, TreeNode* root2){
        if(!root1 && !root2){
            return true;
        }else if( !root1 || !root2 ){
            return false;
        }else{
            if(root1 -> val == root2->val){
                //compare recursively
                //1. root1->left and root2->right
                //2. root1->right and root1 -> left
                return compare(root1->left, root2->right)&&compare(root1->right, root2->left);
            }else{
                return false;
            }
        }
    }
public:
    bool isSymmetric(TreeNode* root) {
        if(!root){
            return true;
        }
        //spit into two trees
        return compare(root->left, root->right);
    }
};

int main(){
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(2);
    root->left->left = new TreeNode(3);
    root->right->left = new TreeNode(3);
    Solution s;
    cout<<s.isSymmetric(root)<<endl;
    
    
    
    return 0;
}

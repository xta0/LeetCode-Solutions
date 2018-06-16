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
    //计算树的深度模板
    int depth(TreeNode* root){
        if(!root){
            return 0;
        }
        if(!root->left && !root->right){
            return 1;
        }
        return 1+max(depth(root->left), depth(root->right));
    }


    int diameterOfBinaryTree(TreeNode* root) {
        if(!root){return 0;}
        if(!root->left && !root->right){ return 0; }
        //每个节点的直径计算为：1(root) + depth(left) + depth(right) - 1
        //递归计算

        int rt = depth(root->left)+depth(root->right);
        int ld = diameterOfBinaryTree(root->left);
        int rd = diameterOfBinaryTree(root->right);
        int ret =  max(rt, max(ld,rd));
        return ret;

    }
};

int main(){




    return 0;
}
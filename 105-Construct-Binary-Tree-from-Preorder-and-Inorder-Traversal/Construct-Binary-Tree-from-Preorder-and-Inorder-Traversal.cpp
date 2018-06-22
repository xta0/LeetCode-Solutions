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
//递归构造
//1. 定位根节点位置，来划分左右两个子树序列
//2. 递归重复1
class Solution {
public:
    TreeNode* helper(vector<int>& preorder, vector<int>& inorder, int rootIndex, int inorder_start, int inorder_end){
        if(inorder_start > inorder_end ){
            return nullptr;
        }
        TreeNode* root  = new TreeNode(preorder[rootIndex]);
        int len = 0;
        for(int i = inorder_start; i<= inorder_end; i++){
            int x = inorder[i];
            if(x == preorder[rootIndex]){
                break;
            }
            len ++;
        }
        //递归求解
        root->left = helper(preorder, inorder, rootIndex+1, inorder_start, inorder_start+len-1);
        root->right = helper(preorder, inorder, rootIndex+1+len, inorder_start+len+1,inorder_end);
        
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(preorder.size() == 0 && inorder.size() == 0){
            return nullptr;
        }
        
        if (preorder.size() == 1 && inorder.size() == 1) {
            return new TreeNode(preorder[0]);
        }
        
        return helper (preorder,inorder,0,0,(int)inorder.size()-1);
        
    }
};

int main(){
    
    vector<int> preorder = {3,9,20,15,7};
    vector<int> inorder = {9,3,15,20,7};
    Solution s;
    TreeNode* root = s.buildTree(preorder,inorder);
    
    
    
    return 0;
}

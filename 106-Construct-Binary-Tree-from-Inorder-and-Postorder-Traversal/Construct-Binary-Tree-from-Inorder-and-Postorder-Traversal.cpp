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

//解法同105
//1. 后序遍历定位根节点
//2. 中序遍历递归创建根节点
class Solution {
public:
    TreeNode* helper(vector<int>& inorder, vector<int>& postorder, int rootIndex, int inorder_start, int inorder_end){
        if(inorder_start > inorder_end ){
            return nullptr;
        }
        TreeNode* root  = new TreeNode(postorder[rootIndex]);
        int len = 0; //左序列长度
        for(int i = inorder_start; i<= inorder_end; i++){
            int x = inorder[i];
            if(x == postorder[rootIndex]){
                break;
            }
            len ++;
        }
        int lenr = inorder_end - inorder_start - len; //右序列长度
        //递归求解
        root->left = helper(inorder, postorder, rootIndex-lenr-1, inorder_start, inorder_start+len-1);
        root->right = helper(inorder, postorder, rootIndex-1, inorder_start+len+1,inorder_end);
        
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if(postorder.size() == 0 && inorder.size() == 0){
            return nullptr;
        }
        if (postorder.size() == 1 && inorder.size() == 1) {
            return new TreeNode(postorder.back());
        }
        
        return helper (inorder, postorder,(int)postorder.size()-1,0,(int)inorder.size()-1);
        
    }
};

int main(){
    vector<int> postorder = {9,15,7,20,3};
    vector<int> inorder = {9,3,15,20,7};
    Solution s;
    TreeNode* root = s.buildTree(inorder,postorder);
    return 0;
}

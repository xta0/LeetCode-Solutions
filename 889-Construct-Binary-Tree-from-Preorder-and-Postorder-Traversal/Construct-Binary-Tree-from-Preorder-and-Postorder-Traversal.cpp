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
/*
Solution: Recursion
Time: O(NlogN) - O(N^2)
Space: O(N)
*/
class Solution {
    /*
    i: start index of curr substree's preorder sequence
    j: start index of curr substree's postorder sequence
    n: curr substree's length
    */
    TreeNode* construct(int i, int j, int n, vector<int>& pre, vector<int>& post){
        if(n == 0){
            return nullptr;
        }
        TreeNode* root = new TreeNode(pre[i]);
        if(n == 1){
            return root;
        }
        //1. find the root node of left subtree;
        int k = j;
        while(post[k] != pre[i+1]){
            k++;
        }
        //2. calculate the length of left subtree and right subtree
        int l = k-j+1;
        int r = n-l-1; 
        root->left = construct(i+1,j,l,pre,post);
        //右子树的preorder起始位置为i+l+1
        //右子树的postorder的起始位置为k+1
        root->right = construct(i+l+1, k+1,r,pre,post);

        return root;
        
    }
public:
    TreeNode* constructFromPrePost(vector<int>& pre, vector<int>& post) {
        return construct(0,0,pre.size(),pre,post);
    }
};

int main(){




    return 0;
}
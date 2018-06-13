#include <iostream>
#include <vector>
#include <string>
#include <queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


//invert using BFS
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if(!root){
            return nullptr;
        }
        if(!root->left && !root->right){
            return root;
        }
        queue<TreeNode* >q;
        q.push(root);
        while(!q.empty()){
            TreeNode* node = q.front();
            q.pop();
            //swap left & right node
            swap(node->left,node->right);
            if(node->left){
                q.push(node->left);
            }
            if(node->right){
                q.push(node->right);
            }
        }
        return root;
    }
};
int main(){




    return 0;
}
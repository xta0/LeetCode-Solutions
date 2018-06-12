#include <iostream>
#include <queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

//BFS，模板同#102
class Solution {
public:
    int minDepth(TreeNode* root) {
        if(!root){
            return 0;
        }
        int depth = 0;
        queue<TreeNode* > q;
        q.push(root);
        while(!q.empty()){
            depth ++;
            int k = q.size();
            for(int i =0; i<k; ++i){
                TreeNode* node = q.front();
                q.pop();
                if(node->left || node->right)
                {
                    if(node->left)
                        q.push(node->left);
                      if(node->right){
                        q.push(node->right);
                      }
                }else{
                    return depth;
                }
            }
        }
        return depth;
    }
};

int main(){

    return 0;
}
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

//BFS
//解法同 #513
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        if(!root){
            return {};
        }
        if(!root->left && !root->right){
            return {root->val};
        }
        vector<int> ret;
        deque<TreeNode* > q;
        q.push_back(root);
        ret.push_back(root->val);
        while(!q.empty()){
            size_t sz = q.size();
            for(int i=0;i<sz;i++){
                TreeNode* node = q.front();
                q.pop_front();
                if(node->left){
                    q.push_back(node->left);
                }
                if(node->right){
                 q.push_back(node->right);
                }
            }
            if(q.size() > 0){
                ret.push_back(q.back()->val);
            }
        }
        return ret;
    }
};

int main(){




    return 0;
}
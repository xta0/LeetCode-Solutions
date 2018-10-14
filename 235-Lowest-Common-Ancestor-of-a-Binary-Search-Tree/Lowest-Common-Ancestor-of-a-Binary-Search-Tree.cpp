#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

class Solution {
public:
    void search(TreeNode* root, TreeNode* node, vector<TreeNode* >& vec){
        vec.push_back(root);
        if(root->val == node->val){
            return;
        }else if(node->val < root->val){
            search(root->left, node, vec);
        }else{
            search(root->right,node,vec);
        }
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root){
            return nullptr;
        }
        vector<TreeNode* >pvec;
        vector<TreeNode* >qvec;
        search(root,p,pvec);
        search(root,q,qvec);
        
        int index = 0;
        while(index<pvec.size() && index<qvec.size() && pvec[index]->val == qvec[index]->val){
            index++;
        }
        return pvec[index-1];
    }
};


int main(){




    return 0;
}
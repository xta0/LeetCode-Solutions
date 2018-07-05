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

class BSTIterator {
    vector<int> arr;
    void dfs(TreeNode* root, vector<int>& arr){
        if(!root){
            return;
        }
        dfs(root->left,arr);
        arr.push_back(root->val);
        dfs(root->right,arr);
    }
public:
    BSTIterator(TreeNode *root) {
        
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        
    }

    /** @return the next smallest number */
    int next() {
        
    }
};

int main(){




    return 0;
}
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
    int index = 0;
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
        dfs(root,arr);
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return index < arr.size();
    }

    /** @return the next smallest number */
    int next() {
        return arr[index++];
    }
};

int main(){




    return 0;
}
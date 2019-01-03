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
Solution: Divide & Conqure + Recursive
Time: O(n)
Space: O(n*n)
*/
/*
Functional Idea
postorder sequence = [left-substree] + [right-subtree]+ root
*/
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        if(!root){
            return {};
        }
        vector<int> res;
        /*
        res = [ 
            postorderTraversal(root->left),
            postorderTraversal(root->rigth),
            root->val
        ]
        */
       auto left = postorderTraversal(root->left);
       auto right = postorderTraversal(root->right);
       res.insert(res.end(),left.begin(),left.end());
       res.insert(res.end(),right.begin(),right.end());
       res.push_back(root->val);
       
       return res;

    }
};

int main(){




    return 0;
}
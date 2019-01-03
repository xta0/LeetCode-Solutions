#include <iostream>
#include <stack>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

/*
Solution: Reverse PostOrder
Time: O(n)
Spce: O(n)
*/
class Solution {
public:
    void reversePreOrder(TreeNode* root, vector<int>& result){
        if(!root){
            return;
        }
        result.push_back(root->val);
        reversePreOrder(root->right,result);
        reversePreOrder(root->left,result);
    }
    vector<int> postorderTraversal(TreeNode* root) {
       vector<int> result;
       reversePreOrder(root,result);

       //返回result 的 reverse
       return {result.rbegin(),result.rend()};
    }
};

int main(){




    return 0;
}
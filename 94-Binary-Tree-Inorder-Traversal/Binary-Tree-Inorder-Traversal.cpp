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
 
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ret;
        stack<TreeNode*> st;
        TreeNode* pointer = root;
        while(!st.empty() || pointer){
            if(pointer){
                st.push(pointer);
                pointer = pointer -> left;
            }else{
                pointer = st.top();
                st.pop();
                ret.push_back(pointer->val);
                pointer = pointer->right;
            }
        }
        
        return ret;
    }
};

int main(){




    return 0;
}
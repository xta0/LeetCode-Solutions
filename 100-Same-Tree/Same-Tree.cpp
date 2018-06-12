#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

//pre-order travsersal
class Solution {
private:
    void dfs(TreeNode* root, string& str){
        if(!root){
            str += "null";
            return ;
        }
        str += to_string(root->val);
        dfs(root->left,str);
        dfs(root->right,str);
    }
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        string s1(""),s2("");
        dfs(p,s1);
        dfs(q,s2);
        return s1==s2;
    }
};

int main(){




    return 0;
}
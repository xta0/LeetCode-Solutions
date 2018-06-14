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

    
class Solution {
    void dfs(TreeNode* root, int& n, int& level, int& max_level){
        
        cout<<root->val<<endl;
        if(root->left){
            level ++;
            dfs(root->left, n,level,max_level);
            level --;
        }else{
            if(level > max_level){
                max_level = level;
                n = root->val;
            }
            return;
        }
        if(root->right){
            level++;
            dfs(root->right,n,level,max_level);
            level --;
        }else{
            if(level > max_level){
                max_level = level;
                n = root->val;
            }
            return;
        }
        
    }
public:
    int findBottomLeftValue(TreeNode* root) {
        int n; int max_level = INT_MIN; int level = 0;
        dfs(root,n,level,max_level);
        return n;
    }
};

int main(){




    return 0;
}
#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

//判断两棵树相同的模板
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(!p && !q){
            return true;
        }else if(!q || !p){
            return false;
        }else{
            if(p->val == q->val){
                return isSameTree(p->left,q->left) && isSameTree(p->right, q->right);
            }else{
                return false;
            }
        }
    }
};

int main(){




    return 0;
}
#include <iostream>
#include <queue>
#include <unordered_map>
using namespace std;

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


//比较模板同 #100
class Solution {
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
public:
    bool isSubtree(TreeNode* s, TreeNode* t) {
        if(isSameTree(s,t)){
            return true;
        }else{
            //自底向上递归比较
            bool b1 = s->left?isSubtree(s->left,t):false;
            bool b2 = s->right?isSubtree(s->right,t):false;
            return b1 || b2;
        }
    }
};
    
int main(){
    return 0;
}
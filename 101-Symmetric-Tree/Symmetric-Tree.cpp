#include <iostream>
#include <queue>
#include <string>
#include <cmath>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        queue<TreeNode* > q;
        q.push(root);
        int level = -1;
        while(!q.empty()){
            level ++;
            string s("");
            for(int i =0; i<std::pow(2,level); ++i){
                TreeNode* node = q.front();
                q.pop();
                if(node){
                    s += to_string(node->val);
                    if(node->left){
                        q.push(node->left);
                    }else{
                        q.push(NULL);
                    }
                    if(node->right){
                        q.push(node->right);
                    }else{
                        q.push(NULL);
                    }
                }else{
                    s+="*";
                }
            }
            string s1 = s;
            cout<<s1<<endl;
            reverse(s1.begin(), s1.end());
            if(s1 != s){
                return false;
            }
        }
        return  true;
    }
};

int main(){
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(2);
    root->left->left = new TreeNode(3);
    root->right->right = new TreeNode(3);
    Solution s;
    cout<<s.isSymmetric(root)<<endl;
    
    
    
    return 0;
}

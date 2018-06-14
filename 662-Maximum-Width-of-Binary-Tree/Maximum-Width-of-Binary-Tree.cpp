#include <iostream>
#include <vector>
#include <string>
#include <queue>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution{
  public:
    int widthOfBinaryTree(TreeNode *root){
        if(!root){
            return 0;
        }
        if(!root->left && !root->right){
            return 0;
        }
        int max_width = 0;
        queue<TreeNode* > q;
        q.push(root);
        while(!q.empty()){
            TreeNode* left= nullptr, *right = nullptr;            
            int l=-1,r=-1;
            queue<TreeNode* >::size_type sz = q.size();
            for(int i = 0; i<sz; ++i){
                TreeNode* node = q.front();
                q.pop();
                if(node){
                    if(node->left || node->right){
                        if(node->left){
                            if(l==-1){
                                l = i;
                            }
                            q.push(node->left);
                        }
                        if(node->right){
                            
                        }
                    }
                    

                }else{
                    if(left){
                        w++;
                    }
                }
                int w = 0;
                
            }
            
            
            if(node->left){
                q.push(node->left);
            }
            if(node->right){
                q.push(node->right);
            }
        }
    }
};

int main()
{

    return 0;
}
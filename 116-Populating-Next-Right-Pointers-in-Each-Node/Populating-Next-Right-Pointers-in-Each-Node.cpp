#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct TreeLinkNode{
    int val;
    TreeLinkNode *left, *right, *next;
    TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};

class Solution {
public:
    //bfs
    void connect(TreeLinkNode *root) {
        if(!root){
            return;
        }
        if(!root->left && !root->right){
            return;
        }
        queue<TreeLinkNode* >q;
        q.push(root);
        while(!q.empty()){
            size_t sz = q.size();
            for(int i =0; i<sz;i ++){
                TreeLinkNode* node = q.front();
                q.pop();
                if(i+1 < sz){
                    TreeLinkNode* next = q.front();
                    node->next = next;
                }
                if(node->left){
                    q.push(node->left);
                }
                if(node->right){
                    q.push(node->right);
                }
            }
        }
    }
};
    
int main(){




    return 0;
}
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };
 //BFS 解法，模板
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
         if(!root){
            return {};
        }
        vector<vector<int>> ret;
        queue<TreeNode* >q;
        q.push(root);
        while(!q.empty()){
            queue<TreeNode* >::size_type sz = q.size();
            vector<int> lv;
            //循环次数为每层元素个数
            for(int i =0; i<sz; ++i){
                TreeNode* node = q.front();
                q.pop();
                lv.push_back(node->val);
                if(node->left){
                    q.push(node->left);
                }
                if(node->right){
                    q.push(node->right);
                }
            }
            ret.push_back(lv);
        }
        return ret;
    }
};

int main(){




    return 0;
}
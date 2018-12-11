#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <unordered_set>
#include <unordered_map>
using namespace std;



  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };
 
class Solution {
    void dfs(TreeNode* root, vector<int>& path, int len, int& maxlen){
        if(!root){
            return;
        }
        dfs(root->left,path,len,maxlen);
        
        if(!path.empty()){
            if(root->val == path.back()){
                len ++;
            }else{
                len = 1;
            }
            maxlen = max(maxlen,len);
        }
        path.push_back(root->val);
        
        dfs(root->right,path,len,maxlen);
    }
public:
    int longestUnivaluePath(TreeNode* root) {
        vector<int> path;
        int maxlen = INT_MIN;
        dfs(root,path,1,maxlen);
        return maxlen-1;
    }
};
int main(){
    Solution s;

    
    
    
    return 0;
}

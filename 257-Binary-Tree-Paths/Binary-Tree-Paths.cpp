#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
//模板同#112， DFS+回溯
class Solution {
    //dfs + backtracking
    //dfs尽量不要设计返回值，很复杂，传入引用变量做判断条件
    void dfs(TreeNode* root, string& chosen, vector<string>& paths){
        if(!root){
            return;
        }
        chosen =  chosen + to_string(root->val)+"->";
        dfs(root->left,chosen,paths);
        dfs(root->right,chosen,paths);
        //检查叶节点位置
        if(!root->left && !root->right){
            if(chosen.back() == '>'){
                chosen.pop_back();
                chosen.pop_back();
            }
            paths.push_back(chosen);
        }
        //backtracking
        string suffix = to_string(root->val);
        chosen = chosen.substr(0,chosen.rfind(suffix));
        
    }
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        string chosen("");
        vector<string> result;
        dfs(root,chosen,result);
        return result;
    }
};

int main(){
    TreeNode* r = new TreeNode(1);
    r->left = new TreeNode(2);
    r->right = new TreeNode(3);
    r->left->right = new TreeNode(5);
    Solution s;
    auto ret = s.binaryTreePaths(r);
    for(auto x: ret){
        cout<<x<<endl;
    }
    return 0;
}

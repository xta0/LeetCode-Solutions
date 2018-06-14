#include <iostream>
#include <map>
#include <queue>

using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

//需要给节点标号,使用pair
class Solution{
public:
    int widthOfBinaryTree(TreeNode *root){
        if(!root){ return 0; }
        if(!root->left && !root->right){ return 1; }

        int max_width = 1;
        deque<pair<TreeNode*,int>> q;
        q.push_back({root, 1});
        while(!q.empty()){
            size_t sz = q.size();
            for(int i = 1; i<=sz; ++i){
                auto pair = q.front();
                q.pop_front();
                if(pair.first->left){
                    q.push_back({pair.first->left, pair.second*2});
                }
                if(pair.first->right){
                    q.push_back({pair.first->right,pair.second*2+1});
                }
            }
            if(q.size() > 1){
                max_width = max(max_width,q.back().second-q.front().second+1);
            }
        }
        return max_width;
    }
};




TreeNode* test1(){
    TreeNode* root =  new TreeNode(1);
    root->right = new TreeNode(3);
    return root;
}
/*
 1
 /   \
 3     2
 /      /
 5       9
 */
TreeNode* test2(){
    TreeNode* root =  new TreeNode(1);
    root->left = new TreeNode(3);
    root->right = new TreeNode(2);
    root->left->left = new TreeNode(5);
    root->right->left = new TreeNode(9);
    return root;
}
/*
 1
 /   \
 3     2
 / \     \
 5   3     9
 */
TreeNode* test3(){
    TreeNode* root =  new TreeNode(1);
    root->left = new TreeNode(3);
    root->right = new TreeNode(2);
    root->left->left = new TreeNode(5);
    root->left->right = new TreeNode(3);
    root->right->right = new TreeNode(9);
    return root;
}

/*
 
 1
 / \
 3   2
 /     \
 5       9
 /         \
 6           7
*/
 
TreeNode* test4(){
    TreeNode* root =  new TreeNode(1);
    root->left = new TreeNode(3);
    root->right = new TreeNode(2);
    root->left->left = new TreeNode(5);
    root->left->right = NULL;
    root->right->right = new TreeNode(9);
    root->right->left = NULL;
    root->left->left->left = new TreeNode(6);
    root->left->left->right = NULL;
    root->right->right->right = new TreeNode(7);
    root->right->right->left = NULL;
    return root;
}

int main()
{
    Solution s;
    cout<<s.widthOfBinaryTree(test1())<<endl;
    cout<<s.widthOfBinaryTree(test2())<<endl;
    cout<<s.widthOfBinaryTree(test3())<<endl;
    cout<<s.widthOfBinaryTree(test4())<<endl;

   
    return 0;
}

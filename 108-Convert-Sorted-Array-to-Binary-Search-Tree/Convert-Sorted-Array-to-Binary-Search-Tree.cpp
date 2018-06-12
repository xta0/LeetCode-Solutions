#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        vector<int>::size_type sz = nums.size();
        if(sz == 0){
            return nullptr;
        }
        if(sz == 1){
            return new TreeNode(nums[0]);
        }
        TreeNode* root = new TreeNode(nums[sz/2]);
        vector<int> left(nums.begin(), nums.begin() + sz/2);
        root->left = sortedArrayToBST(left);
        vector<int> right(nums.begin()+sz/2+1, nums.end());
        root->right = sortedArrayToBST(right);
        return root;
    }
};
int main(){
//    vector<int> array = {-10,-3,0,5,9};
     vector<int> array = {-3,0,5,9};
    Solution s;
    s.sortedArrayToBST(array);
    return 0;
}

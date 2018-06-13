#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        vector<int>::size_type sz = nums.size();
        if(sz == 0){
            return nullptr;
        }
        if(sz == 1){
            return new TreeNode(nums[0]);
        }
        int max = INT_MIN;
        int max_index = 0;
        for(int i = 0; i<sz; ++i){
            if(nums[i] > max){
                max = nums[i];
                max_index = i;
            }
        }
        //step1: create root node 
        TreeNode* root = new TreeNode(max);
        //step2: split nums into two parts
        vector<int> left = {nums.begin(), nums.begin()+max_index};
        vector<int> right = {nums.begin() + max_index + 1, nums.end()};
        //step3: build recursively
        root->left = constructMaximumBinaryTree(left);
        root->right = constructMaximumBinaryTree(right);
        return root;
    }
};

int main(){




    return 0;
}
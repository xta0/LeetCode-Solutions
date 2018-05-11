#include <iostream>
#include <stack>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
private:
    enum Tag{left, right};
    struct TreeNodeElement{
        TreeNode* pointer;
        Tag tag;
        TreeNodeElement(TreeNode* node):pointer(node){
            tag = left;
        }
    } ;
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ret;
        stack<TreeNodeElement> st;
        TreeNode* pointer = root;
        while(pointer || !st.empty()){
            while(pointer){
                TreeNodeElement ele(pointer);
                ele.tag = left;
                st.push(ele);
                pointer = pointer->left;
            }
            TreeNodeElement top = st.top();
            st.pop();
            pointer = top.pointer;
            if(top.tag == left){
                top.tag = right;
                st.push(top);
                pointer = pointer->right;       
            }else{
                ret.push_back(pointer->val);
                pointer = NULL;
            }
        }
        return ret;      
    }
};

int main(){




    return 0;
}
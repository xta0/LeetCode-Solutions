#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };
 
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

//链表中间的点为根节点，前一部分的中间节点为左孩子，后一部分的中间节点为右孩子，左右部分依次递归
class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        if(!head){
            return nullptr;
        }
        if(!head->next){
            return new TreeNode(head->val);
        }
        int len = 0;
        ListNode* root = head;
        ListNode* p = head;
        while(p){
            len ++;
            p = p->next;
            if(len % 2 == 0){
                root=root->next;
            }
        }
        
        ListNode* right = root->next;
        root->next = nullptr;
        ListNode* left = head;
        while(left->next != root){
            left = left->next;
        }
        left->next = nullptr;
        
        TreeNode* r = new TreeNode(root->val);
        r->left = sortedListToBST(head);
        r->right = sortedListToBST(right);
        return r; 
    }
};

void dfs(TreeNode* root){
    if(!root){
        return;
    }
    if(root->left){
        dfs(root->left);
    }
    cout<<root->val<<endl;

    if(root->right){
        dfs(root->right);
    }
}

int main(){
    Solution s;
    ListNode* head = new ListNode(-10);
    head->next = new ListNode(-3);
    head->next->next = new ListNode(0);
    head->next->next->next = new ListNode(5);
    head->next->next->next->next = new ListNode(9);
    TreeNode* root = s.sortedListToBST(head);
    dfs(root);


    return 0;
}
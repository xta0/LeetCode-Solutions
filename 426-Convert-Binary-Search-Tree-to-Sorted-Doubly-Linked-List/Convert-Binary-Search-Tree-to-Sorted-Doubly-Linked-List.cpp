#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Node{
    int val;
    Node *left;
    Node *right;
    Node(int x) : val(x), left(NULL), right(NULL) {}
};
//1. inorder，keep tracking prev element
//2. connect prev ele to root or vice versa, three cases
//3. connect the start with the end
class Solution {
public:
    void inorderTraversal(Node* root, Node*& prev, Node*& start){
        if(!root){
            return;
        }
        inorderTraversal(root->left,prev,start);
        if(!start){
            start = root;
        }
        //
        cout<<"node: "<<root->val;
        if(prev){
            cout<<", prev: "<<prev->val;
        }else{
            cout<<", prev: null";
        }
        cout<<endl;
        
        //connect
        if(prev){
            if(root->left == prev){
                prev->right = root;
            }else if(prev->right == root){
                root->left = prev;
            }else{
                prev->right = root;
                root->left = prev;
            }
        }
        prev= root;
        inorderTraversal(root->right,prev,start);
    }
    Node* treeToDoublyList(Node* root) {
        
        Node* prev = nullptr;
        Node* start = nullptr;
        inorderTraversal(root,prev,start);
        start -> left = prev;
        prev->right = start;
        

        return start;
    }
};
int main(){
    Node* root = new Node(4);
    root->left = new Node(2);
    root->right = new Node(5);
    root->left->left  = new Node(1);
    root->left->right = new Node(3);
    Solution s;
    s.treeToDoublyList(root);
    
    return 0;
}

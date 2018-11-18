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
    
class Solution {
    Node* subTree(){

    }
public:
    Node* treeToDoublyList(Node* root) {
        Node* left ;
        Node* right;
        root->left = left;
        root->right = right;
        left ->right = root;
        right->left = root;
        left ->left = right;
        right->right = left;
    }
};
int main(){




    return 0;
}
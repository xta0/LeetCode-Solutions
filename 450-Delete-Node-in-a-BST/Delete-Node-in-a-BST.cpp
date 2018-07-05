#include <iostream>
using namespace std;

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    ~TreeNode(){
        cout<<"deleted: "<<this<<endl;
    }
};
//search
TreeNode* search(TreeNode* node, int target){
    if(!node || node->val == target){
        return node;
    }
    //递归
    if(target < node->val){
        return search(node->left,target);
    }else{
        return search(node->right,target);
    }
}
//insert
void insert(TreeNode* node,int target){
    if( target == node->val  ){
        return; //禁止重复元素插入
    }else if(target < node->val){
        if(!node->left){
            node ->left = new TreeNode(target);
            return;
        }else{
            insert(node->left,target);
        }
    }else{
        if(!node->right){
            node->right = new TreeNode(target);
            return;
        }else{
            insert(node->right,target);
        }
    }
}
//delete
TreeNode* deleteNode(TreeNode* root, int key) {
    if(!root){
        return NULL;
    };
    if(root->val < key){
        root->right = deleteNode(root->right,key);
    }else if(root->val > key){
        root->left = deleteNode(root->left,key);
    }else{
        if(!root->left && !root->right){
            delete root;
            return NULL;
        }else if(!root->left){
            TreeNode* right = root->right;
            delete root;
            return right;
        }else if(!root->right){
            TreeNode* left = root->left;
            delete root;
            return left;
        }else{
            TreeNode* rt = root->right;
            while(rt->left){
                rt = rt->left;
            }
            root->val = rt->val;
            root->right = deleteNode(root->right,rt->val);
        }
    }
    return root;        
}

void inorder(TreeNode* root){
    if(!root){
        return;
    }
    inorder(root->left);
    cout<<root->val<<":"<<root<<endl;
    inorder(root->right);
    
}

int main(){
    auto print = [](TreeNode* root,string msg)->void{
        cout<<msg<<endl;
        inorder(root);
        cout<<endl;
    };
    TreeNode* root = new TreeNode(5);
    insert(root,3);
    insert(root,6);
    insert(root,2);
    insert(root,4);
    insert(root,7);
    print(root,"before delete");
    deleteNode(root,3);
    print(root,"after delete");
    
    return 0;
}

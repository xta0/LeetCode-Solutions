
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

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

//对nullptr使用终止符表示
class Codec {
    void preorderSerialize(TreeNode* root, string& str){
        if(!root){
            str+="# ";
            return ;
        }
        str = str + to_string(root->val) + " ";
        
        preorderSerialize(root->left,str);
        preorderSerialize(root->right,str);
    }
    TreeNode* preorderDeserialize(vector<string>& str, int& index){
        if(index == str.size()-1 || str[index]=="#"){
            return nullptr;
        }
        TreeNode* root = new TreeNode(stoi(str[index]));
        index ++;
        root->left = preorderDeserialize(str,index);
        index ++;
        root->right = preorderDeserialize(str,index);
        return root;
    }
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string str="";
        preorderSerialize(root,str);
        return str;
    }
    
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        //lamda function
        //"3,10,#,333" -> ["3","10","#","333"]
        auto func = [](string& str){
            vector<string> arr;
            int prevPos = 0;
            for(int i=0;i<str.size();i++){
                if(str[i]==' '){
                    string tmp = str.substr(prevPos,i-prevPos);
                    if(i+1<str.size()){
                        prevPos = i+1;
                    }
                    arr.push_back(tmp);
                }
            }
            return arr;
        };
        vector<string> arr = func(data);
        int index = 0;
        return preorderDeserialize(arr,index);
    }
};


bool isSameTree(TreeNode* root1, TreeNode* root2){
    if(!root1 && !root2){
        return true;
    }
    if(!root1 || !root2){
        return false;
    }
    bool b1 = root1->val == root2->val;
    bool b2 = isSameTree(root1->left, root2->left);
    bool b3 = isSameTree(root1->right, root2->right);
    return b1&&b2&&b3;
}

int main(){
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);
    
    Codec c;
    string ser = c.serialize(root);
    auto node = c.deserialize(ser);
    cout<<isSameTree(node, root)<<endl;
    
    
    
    
    return 0;
}

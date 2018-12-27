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


// Definition for a Node.
class Node {
public:
    int val = NULL;
    vector<Node*> children;

    Node() {}

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

/*
Solution: Queue
Time: O(N)
Space:O(N)

序列化:
1. 使用先根遍历
2. 每个节点保存两个信息：val和children的size，用空格分割，节点间用空格分割
3. 递归求解

反序列化：
1. 按空格分割字符串，string -> queue<int>
2. 使用先跟遍历，每次从queue中pop出两个数，第一个是节点值，第二个是children的size
3. 递归求解
*/
class Codec {
public:

    void rootFirstSerialize(Node* root, string& strs){
        if(!root){
            return;
        }
        strs += to_string(root->val);
        strs += " ";
        strs += to_string(root->children.size());
        strs += " ";
        for(auto node : root->children){
            rootFirstSerialize(node,strs);
        }
    }
    // Encodes a tree to a single string.
    string serialize(Node* root) {
        string strs="";
        rootFirstSerialize(root,strs);
        return strs;
    }
    Node* rootFirstDeserialize(queue<int>& nums){
        if(nums.size() < 2){
            return nullptr;
        }
        
        int val = nums.front();
        nums.pop();
        int n = nums.front();
        nums.pop();
        
        Node* root = new Node(val,{});
        for(int i=0;i<n;i++){
            root->children.push_back(rootFirstDeserialize(nums));
        }
        return root;
        
    }

    // Decodes your encoded data to tree.
    Node* deserialize(string data) {
        queue<int> nums;
        string tmp = "";
        int prev = 0;
        for(int i=0;i<data.size();i++){
            char c = data[i];
            if(c == ' '){
                tmp = data.substr(prev,i-prev);
                nums.push(stoi(tmp));    
                prev = i+1;
                tmp = "";
            }
        }
        return rootFirstDeserialize(nums);
        
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));

int main(){




    return 0;
}
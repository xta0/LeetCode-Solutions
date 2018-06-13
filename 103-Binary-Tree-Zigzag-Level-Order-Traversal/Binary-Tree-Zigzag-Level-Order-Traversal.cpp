#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

/*
 BFS.解法模板同 #102
 对于zigzag order
 1. 使用vector不断insert front比较直观
 2. 用双向队列 deque，效率更高，但是要处理节点入栈顺序
 */

class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(!root){return {};}
        vector<vector<int>> ret;
        //The zigzag order requires you to dequeue an item from back the queue,
        //thus we need a double-end queue.
        deque<TreeNode* >q;
        q.push_back(root);
        int level = 0;
        //BFS traveral
        while(!q.empty()){
            //number of elements in each level
            queue<TreeNode* >::size_type sz = q.size();
            vector<int> lv;
            //for each loop, increment the level value by 1
            level ++ ;
            for(int i =0; i<sz; ++i){
                TreeNode* node = nullptr;
                if(level % 2 == 1){
                    //1. dequeue an item from front
                    //2. enqueue children items from left to right
                    //3. push them in the back
                    node = q.front();
                    q.pop_front();
                    if(node->left){q.push_back(node->left);}
                    if(node->right){q.push_back(node->right);}
                }else{
                    
                    //1. dequeue an item from back 
                    //2. enqueue children items from right to left
                    //3. push them in the font
                    node = q.back();
                    q.pop_back();
                    if(node->right){q.push_front(node->right);}
                    if(node->left){q.push_front(node->left);}
                }
                //collect the results
                lv.push_back(node->val);
            }
            ret.push_back(lv);
        }
        return ret;
    }
};

int main(){
    
    
    
    
    return 0;
}

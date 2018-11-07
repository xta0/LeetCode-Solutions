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

struct RandomListNode {
    int label;
    RandomListNode *next, *random;
    RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
};

//Deep copy问题，使用hashmap+递归
//类似Clone  Graph
//O(n)
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        unordered_map<RandomListNode*, RandomListNode* > um;
        return copy(head,um);
    }
    RandomListNode* copy(RandomListNode* head,unordered_map<RandomListNode* , RandomListNode* >& um){
        if(!head){
            return nullptr;
        }
        RandomListNode* root = new RandomListNode(head->label);
        um[head] = root;
        if(um[head->next]){
            root->next = um[head->next];
        }else{
            root->next = copy(head->next,um);
        }
        if(um[head->random]){
            root->random = um[head->random];
        }else{
            root->random= copy(head->random,um);
        }
        return root;
    }
};

int main(){




    return 0;
}
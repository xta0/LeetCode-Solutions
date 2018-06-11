#include <iostream>
using namespace std;

struct RandomListNode {
    int label;
    RandomListNode *next, *random;
    RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
};

class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        if(!head){
            return head;
        }
        RandomListNode* l1 = head;
        RandomListNode* new_head = new RandomListNode(l1->label);
        RandomListNode* l2 = new_head;

        //step 1: deep copy all nodes
        while(l1->next){
            l2->next = new RandomListNode(l1->next->label);
            l2 = l2->next;
            l1 = l1->next;
        }        
        l2 = new_head;
        l1 = head;
    
        //step2: connect random nodes
        while(l1){
            RandomListNode* ll1 = head;
            RandomListNode* ll2 = new_head;
            if(l1->random){
                while(ll1){
                    if(ll1 == l1->random){
                        l2->random = ll2;
                        break;
                    }
                    ll1 = ll1->next;
                    ll2 = ll2->next;
                }
            }else{
                l2->random = nullptr;
            }
            l1 = l1->next;
            l2 = l2->next;
        }
    
        return new_head;
    }

};

int main(){




    return 0;
}
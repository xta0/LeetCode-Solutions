#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(!headA || !headB){
            return nullptr;
        }
        int la = 0; int lb = 0;
        ListNode* pa = headA;
        ListNode* pb = headB;
        while(pa){
            la++; 
            lb++;
            pa= pa ->next;
            pb= pb ->next;
        }      
        while(pb){
            lb++;
            pb = pb->next;
        }
        while(pa){
            pa++;
            pa = pa->next;
        }
        
        if(la >= lb){
            int delta = la - lb;
            for(int i =0; i<delta; ++i){
                headA = headA->next;
            }
        }else{
            int delta = lb - la;
            for(int i=0;i<delta; ++i){
                headB = headB -> next;
            }
        }

        while(headA && headB){
            if(headA == headB){
                return headA;
            }else{
                headA = headA -> next;
                headB = headB -> next;
            }
        }
        return nullptr;
        
    }
};

int main(){




    return 0;
}
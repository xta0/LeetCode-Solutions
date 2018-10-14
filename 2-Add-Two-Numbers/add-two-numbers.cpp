#include <iostream>
using namespace std;

struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode node(0);
        ListNode* tmp  = &node;
        ListNode* head = tmp; 
        bool carray = false;
        while(l1 || l2){
            
            //calculate value
            int value = (l1?l1->val:0) + (l2?l2->val:0);
            if(carray){
                value += 1;
            }
            if(value >= 10){
                value -= 10;
                carray = true;
            }else{
                carray = false;
            }      
           
            //update tmp
            if(l1){
                l1->val = value;
                tmp->next= l1;
                tmp = tmp->next;
            }else{
                if(l2){
                    l2->val = value;
                    tmp->next = l2;
                    tmp = tmp->next;
                }
            }
            
            //update l1 & l1
            if(l1){
                l1=l1->next;
            }
            if(l2){
                l2 = l2->next;
            }
        }
         if(carray){
            tmp->next = new ListNode(1);
        }
        return head->next;
    } 
};

int main(){




    return 0;
}
 
 
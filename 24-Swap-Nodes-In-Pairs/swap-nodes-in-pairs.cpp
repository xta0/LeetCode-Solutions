#include <iostream>
using namespace std;
 
struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode* pos = head;
        while(pos!= NULL){
            if(pos->next == NULL){
                break;
            }
            int tmp = pos->val;
            pos->val = pos->next->val;
            pos->next->val = tmp;
            pos = pos->next->next;
        }   
        return head;     
    }
};

int main(){




    return 0;
}
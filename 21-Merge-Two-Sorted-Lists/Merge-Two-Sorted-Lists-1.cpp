#include <iostream>
using namespace std;

struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2){
        ListNode* ret = NULL;
        ListNode* pos = NULL;
        while(l1 && l2){
            int value1 = l1->val;
            int value2 = l2->val;
            int val = value1 <= value2?value1:value2;
            if(!ret){
                ret = new ListNode(val);
                pos = ret;
            }else{
                pos->next = new ListNode(val);
                pos =pos->next;
            }
            if(value1<=value2){
                l1 = l1 -> next;
            }
            if(value1>value2){
                l2 = l2 -> next;
            }
        }
        
        //append l2
        while(l2){
            ListNode* node = new ListNode(l2->val);
            if(!ret){
                ret = node;
                pos = ret;
            }else{
                pos->next = node;
                pos = pos->next;
            }
            l2 = l2->next;
        }
        //apped l1
        while(l1){
            ListNode* node = new ListNode(l1->val);
            if(!ret){
                ret = node;
                pos = ret;
            }else{
                pos->next = node;
                pos = pos->next;
                
            }
            l1 = l1->next;
        }
        
        return ret;
    }
};

int main(){
    return 0;
}

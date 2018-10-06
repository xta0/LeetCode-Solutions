#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        if(!head || !head->next){
            return head;
        }
        ListNode* fast = head;
        ListNode* slow = head;
        while(fast->next){
            if(fast->next->next){
                fast = fast->next->next;
            }else{
                fast = fast->next;
            }
            slow = slow->next;
        }
        return slow;
    }
};
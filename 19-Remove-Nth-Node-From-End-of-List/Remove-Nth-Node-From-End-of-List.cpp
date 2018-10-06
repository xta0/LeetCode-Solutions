#include <iostream>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* p = head;
        ListNode* runner = head;
        int count = 0;
        while(p->next){
            p = p->next;
            count ++;
            if(count > n){
                runner = runner->next;
            }
        }
        if(count + 1 == n){
            //remove head
            return head->next;
        }else if(count+1 < n){
            return head;
        }else{
            ListNode* tmp = runner->next->next;
            runner->next = tmp;
            return head;
        }
    }
};

int main()
{
    //test case;
    //[]
    //[1],1
    //[1,2],2
    //[1,2,3,4,5],2
    return 0;
}

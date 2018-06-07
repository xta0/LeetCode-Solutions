#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
private:
    ListNode* reverseList(ListNode* head){
        ListNode* p1 = nullptr;
        ListNode* p2 = nullptr;
        while(head){
            p2 = head;
            head = head->next;
            p2 -> next = p1;
            p1 = p2;
        }
        return p1;
    }
public:
    void reorderList(ListNode* head) {
        if(!head){
            return nullptr;
        }
        
        int len = 0;
        ListNode* p = head;
        while(p){
            p = p->next;
            len ++;
        }
        int index = len % 2 == 0 ? len/2 : len/2+1;
        int k = 0;
        p = head;
        while(k != index){
            p = p->next;
            k++;
        }
        ListNode* q = reverseList(p);
        p = head;
        while(q){
            ListNode* tmpp  = p;
            p = p->next;
            ListNode* tmpq = q;
            q = q->next;
            tmpp->next = tmpq;
            tmpq->next = p; 
        }
        return head;
    }
};


int main(){




    return 0;
}
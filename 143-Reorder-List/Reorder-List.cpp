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
            p1 = head;
            head = head->next;
            p1 -> next = p2;
            p2 = p1;
        }
        return p2;
    }
public:
    void reorderList(ListNode* head) {
        if(!head){
            return;
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
    }
};


int main(){

    Solution s;
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    s.reorderList(head);
    while(head){
        cout<<head->val<<endl;
        head = head->next;
    }
    return 0;


    return 0;
}
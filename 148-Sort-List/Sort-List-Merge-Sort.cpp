#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

//merge sort
class Solution {
    ListNode* mergeSort(ListNode* head, int len){
        if(len == 1){
            return head;
        }
        //step1: split list into two half
        int pos = len/2-1;
        ListNode* p = head;
        ListNode* q = nullptr;
        int k = 0;
        while(k<pos){
            p = p->next;
            k ++;
        }
        q = p->next;
        p->next = nullptr;
        p = head;
        
        //step2: sort halves recursively
        p = mergeSort(p,k+1);
        q = mergeSort(q,len-k-1);
        
        //step3: merge p and q
        ListNode* z = nullptr;
        ListNode* x = nullptr;
        while(p&&q){
            if(p->val < q->val){
                if(!z){
                    z = p;
                    x = z;
                }else{
                    x ->next = p;
                    x = x->next;
                }
                p = p->next;
            }else{
                if(!z){
                    z = q;
                    x = z;
                }else{
                    x->next = q;
                    x = x->next;
                }
                q = q->next;
            }
        }
        if(!p){
            x -> next = q;
        }
        if(!q){
            x-> next = p;
        }
        return z;
    }
public:
    ListNode* sortList(ListNode* head) {
        if(!head){
            return head;
        }
        int len = 0;
        ListNode* p = head;
        while(p){
            p = p->next;
            len ++;
        }
        if(len == 1){
            return head;
        }
        return mergeSort(head, len);
    }
};

int main(){
    Solution s;
    ListNode* head = new ListNode(-1);
    head->next = new ListNode(5);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(0);
//    ListNode* head = new ListNode(4);
//    head->next = new ListNode(2);
//    head->next->next = new ListNode(1);
//    head->next->next->next = new ListNode(3);
////    head->next->next->next->next = new ListNode(0);
    head = s.sortList(head);
    while(head){
        cout<<head->val<<" ";
        head = head->next;
    }
    return 0;
}

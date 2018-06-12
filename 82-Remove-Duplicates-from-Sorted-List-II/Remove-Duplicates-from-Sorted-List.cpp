#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        
        //at least two elements in the list
        if(!head || !head->next){
            return head;
        }
        ListNode* p1 = nullptr; //pointer to mark the first duplicated element
        ListNode* p2 = head; //pointer to mark the last duplicated element
        
        while(p2&&p2->next){
            if(p2->val == p2->next->val){
                p1 = p2; //locate p1
                //skip duplicated elements
                while(p2->next&&p2->val == p2->next->val){
                    p2 = p2->next;
                }
                //if we get there, there are 2 possible situations:
                //1. p2->next = nullptr;
                //2. p2->val != p2->next->val
                //for either situation, we have the same logic
                //the idea is to connect the pointer before p1 and the pointer after p2
                if(p1 == head){
                    head = p2->next;
                }else{
                    //find the pointer before p1
                    ListNode* p = head;
                    while(p->next != p1){
                        p = p->next;
                    }
                    p->next = p2->next; //delete the duplicated elements
                }
            }
            p2 = p2->next;
        }
        return head;
    }
};

int main(){
    
    Solution s;
    ListNode* node = new ListNode(1);
    node->next = new ListNode(2);
    node->next->next = new ListNode(3);
    node->next->next->next = new ListNode(3);
    node->next->next->next->next = new ListNode(4);
    node->next->next->next->next->next = new ListNode(4);
    node->next->next->next->next->next->next = new ListNode(5);
//    ListNode* node = new ListNode(1);
//    node->next = new ListNode(1);
//    node->next->next = new ListNode(3);
//    node->next->next->next = new ListNode(3);
//    node->next->next->next->next = new ListNode(4);
//    node->next->next->next->next->next = new ListNode(4);
//    node->next->next->next->next->next->next = new ListNode(5);
    ListNode* head = s.deleteDuplicates(node);
    while(head){
        cout<<head->val<<" ";
        head=head->next;
    }
    cout<<endl;
    return 0;
}

#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
/*
Solution: Merge Sort
Time: O(nlogn)
Space: O(n)
*/
class Solution {
    ListNode* mergeSort(ListNode* l1, ListNode* l2){
        if(!l1){
            return l2;
        }
        if(!l2){
            return l1;
        }
        if(l1->val < l2->val){
            l1->next = mergeSort(l1->next,l2);
            return l1;
        }else{
            l2->next = mergeSort(l1,l2->next);
            return l2;
        }
        
    }
    public:
    ListNode* sortList(ListNode* head) {
        if(!head || !head->next){
            return head;
        }
        ListNode* fast = head->next;
        ListNode* slow = head;
        while(fast&&fast->next){
            fast = fast->next->next;
            slow = slow->next;
        }
        ListNode* mid = slow->next;
        slow->next = nullptr;
        return mergeSort(sortList(head),sortList(mid));
        
        
    }
};

int main(){
    Solution s;
//    ListNode* head = new ListNode(-1);
//    head->next = new ListNode(5);
//    head->next->next = new ListNode(3);
//    head->next->next->next = new ListNode(4);
//    head->next->next->next->next = new ListNode(0);
        ListNode* head = new ListNode(4);
        head->next = new ListNode(2);
        head->next->next = new ListNode(1);
        head->next->next->next = new ListNode(3);
        head->next->next->next->next = new ListNode(0);
    head = s.sortList(head);
    while(head){
        cout<<head->val<<" ";
        head = head->next;
    }
    return 0;
}

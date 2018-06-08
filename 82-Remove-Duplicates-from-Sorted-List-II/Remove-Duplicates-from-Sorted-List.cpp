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
        if(!head){
            return head;
        }
        ListNode* p1 = head;
        ListNode* p2 = head->next;
        while(p1 && p2){
            if(p1 -> val != p2->val){
                if(!p2->next){
                    break;
                }
                if(p2->next != p2){
                    p1 = p1->next;
                }
                p2 = p2->next;
            }else{
                while( p1->val == p2->val){
                    p2 = p2->next;
                    if(!p2){
                        break;
                    }
                }
                p1->next = p2;
            }
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
    
    ListNode* head = s.deleteDuplicates(node);
    while(head){
        cout<<head->val<<" ";
        head=head->next;
    }
    cout<<endl;
    return 0;
}
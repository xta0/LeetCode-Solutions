#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

//O(n^2)
class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        if(!head){
            return nullptr;
        }
         ListNode* root = new ListNode(head->val);
        head = head->next;
        while(head){
            int data = head->val;
            ListNode* node = new ListNode(data);
            if(data < root->val){
                node->next = root;
                root = node;
            }else{
                ListNode* tmp = root;
                while(tmp->next && data>tmp->next->val){
                    tmp = tmp->next;
                }
                if(!tmp->next){
                    tmp -> next = node;
                }else{
                    ListNode* next = tmp->next ;
                    tmp->next = node;
                    node->next = next;
                }
            }
            head=head->next;
        }
        
        return root;
    }
};

int main(){




    return 0;
}
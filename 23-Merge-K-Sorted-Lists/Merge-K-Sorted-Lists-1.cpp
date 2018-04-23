#include <iostream>
#include <vector>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {

public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* head = NULL;
        ListNode* pos = NULL;
        while(true){
            int min_index = -1;
            int min_val =1<<30;
            bool finished = true;
            for(int i=0;i<lists.size();++i){
                ListNode* node = lists[i];
                if(node){
                    int val = node->val;
                    if(val < min_val){
                        min_index = i;
                        min_val = val;
                    }
                    finished = false;
                }
            }
            if(finished){
                break;
            }else{
                ListNode* node = new ListNode(min_val);
                if(head){
                    pos ->next =  node;
                    pos = pos-> next;
                }else{
                    head = new ListNode(min_val);
                    pos = head;
                }
                //update the head of the list
                lists[min_index] = lists[min_index]->next;
            }
        }
        return head;
    }
};

int main(){
    ListNode* n1 = new ListNode(1);
    n1->next = new ListNode(4);
    n1->next->next = new ListNode(5);
    
    ListNode* n2 = new ListNode(1);
    n2->next = new ListNode(3);
    n2->next->next = new ListNode(4);
    
    ListNode* n3 = new ListNode(2);
    n3->next = new ListNode(6);
    
    Solution s;
    vector<ListNode* >v{n1,n2,n3};
    ListNode* head = s.mergeKLists(v);
    
    return 0;
}

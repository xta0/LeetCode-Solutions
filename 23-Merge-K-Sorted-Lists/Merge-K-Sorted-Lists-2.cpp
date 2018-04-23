#include <iostream>
#include <vector>
using namespace std;

struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
private:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2){
        if(l1 == NULL){
            return l2;
        }
        if(l2 == NULL){
            return l1;
        }
        if(l1->val <= l2->val){
            l1->next = mergeTwoLists(l1->next, l2);
            return l1;
        }else{
            l2->next = mergeTwoLists(l1, l2->next);
            return l2;
        }
    }
public:
    // [[[[],l1]l2]l3]...
    ListNode* mergeRecursively(ListNode* l1, vector<ListNode*>& lists, int index){
        if(index == lists.size()-1){
            return l1;
        }else{
            ListNode* l2 = lists[index];
            index += 1;
            return mergeRecursively(mergeTwoLists(l1,l2),lists,index);
        }
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        return mergeRecursively(NULL,lists,0);
    }
};

int main(){
    return 0;
}

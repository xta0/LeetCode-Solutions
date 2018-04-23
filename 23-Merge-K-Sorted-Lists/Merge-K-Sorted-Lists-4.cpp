#include <iostream>
#include <queue>
using namespace std;

struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* head = NULL;
        auto cmp = [](const ListNode* l1, const ListNode* l2){
            return l1->val > l2->val;
        };
        priority_queue<ListNode*,std::vector<ListNode* >,decltype(cmp)> pq(cmp);
        for(auto x:lists){
            if(x){
                pq.push(x);
            }
        }
        if(pq.size() == 0){
            return NULL;
        }
        head = pq.top();
        pq.pop();
        ListNode* pos = head;
        while(!pq.empty()){
            if(pos->next){
                pq.push(pos->next);
            }
            pos->next = pq.top();
            pos = pos->next;
            pq.pop();
        }
        
        return head;
    }
};

int main(){
//    ListNode* n1 = new ListNode(1);
//    n1->next = new ListNode(4);
//    n1->next->next = new ListNode(5);
//
//    ListNode* n2 = new ListNode(1);
//    n2->next = new ListNode(3);
//    n2->next->next = new ListNode(4);
//
//    ListNode* n3 = new ListNode(2);
//    n3->next = new ListNode(6);
//

//    vector<ListNode* >v{n1,n2,n3};

    Solution s;
    vector<ListNode* >v{NULL};
    ListNode* head = s.mergeKLists(v);
    return 0;
}

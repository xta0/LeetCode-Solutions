#include <iostream>
using namespace std;

struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

//O(n)
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if( !head ){
            return head;
        }
        int len = 1;
        ListNode* tail = head;
        while(tail->next){
            len ++;
            tail = tail->next;
        }
        k  = k%len;
        if(k == 0){
            return head;
        }
        //成环
        tail->next = head;
        
        //找到切割点
        tail = head;
        
        //切割节点位于(len-k)th的位置,移动(len-k-1)次,需要归纳推演
        for(int i=0;i<len-k-1;++i){
            tail = tail -> next;
        }
        
        head = tail->next;
        tail->next = nullptr;
        
        return head;
    }
};

int main(){
    
    Solution s;
    ListNode* node = new ListNode(1);
    node->next = new ListNode(2);
    node->next->next = new ListNode(3);
    node->next->next->next = new ListNode(4);
    node->next->next->next->next = new ListNode(5);
    
    ListNode* head = s.rotateRight(node,1);
    while(head){
        cout<<head->val<<" ";
        head=head->next;
    }
    cout<<endl;
    return 0;
}

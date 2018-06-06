#include <iostream>
using namespace std;

struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

//O(n^2)
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if( !head ){
            return head;
        }
        int len = 0;
        ListNode* lenp = head;
        while(lenp){
            len ++;
            lenp = lenp->next;
        }
        k  = k%len;
        for(int i=0;i<k;++i){
            ListNode* firstp = head->next;
            ListNode* secondp = head;
            if(!firstp){
                return head;
            }
            //找到尾部节点和尾部节点的前一个节点
            while(firstp->next){
                firstp = firstp->next;
                secondp = secondp->next;
            }

            //尾部指向头部，尾部前一个节点变成尾部
            firstp->next = head;
            secondp->next = nullptr;
            head = firstp;
        }
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
    
    ListNode* head = s.rotateRight(node,2);
    while(head){
        cout<<head->val<<" ";
        head=head->next;
    }
    cout<<endl;
    return 0;
}

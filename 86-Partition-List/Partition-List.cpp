#include <iostream>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

//创建两个列表, 小于x的一个链表，大于等于x的一个链表，最后合并两个链表
//需要在heap申请空间，不算快
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        if(!head){
            return head;
        }
        ListNode* p1 = nullptr, *p11 = nullptr;
        ListNode* p2 = nullptr, *p22 = nullptr;
        while(head){
            if(head->val < x){
                if(!p1){
                    p1 = new ListNode(head->val);
                    p11 = p1;
                }else{
                    p11->next = head;
                    p11 = p11->next;
                }
            }else{
                if(!p2){
                    p2 = new ListNode(head->val);
                    p22 = p2;
                }else{
                    p22->next = head;
                    p22 = p22->next;
                }
            }
            head = head->next;
        }
        
        if(p22){
            p22->next = nullptr;
        }
        if(p1){
            p11->next = p2;
            return p1;
        }else{
            return p2;
        }
    }
};

int main(){
    
    Solution s;
    ListNode* head = new ListNode(1);
    head->next = new ListNode(4);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(2);
    head->next->next->next->next = new ListNode(5);
    head->next->next->next->next->next = new ListNode(2);
    ListNode* last = s.partition(head,3);
    while(last){
        cout<<last->val<<endl;
        last = last->next;
    }
    
    
    return 0;
}

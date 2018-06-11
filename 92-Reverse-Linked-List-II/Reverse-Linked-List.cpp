#include <iostream>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
private:
    ListNode* reverse(ListNode* head){
        ListNode* p = nullptr;
        ListNode* q = nullptr;
        while(head){
            p = head;
            head = head->next;
            p->next = q;
            q = p;
        }
        return q;
    }
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        
        //step 0: corner case
        if(!head){
            return head;
        }
        if(n <= m ){
            return head;
        }

        //step 1: locate the boundary nodes
        ListNode* start=nullptr,* prev = nullptr;
        ListNode* end=nullptr, *tail = nullptr;
        
        int k = 1;
        ListNode* p = head;
        //翻转起始节点，起始节点前一个节点，终结点，终结点后一个节点
        while(k <=n && p){
            if(k == m-1){
                prev = p;
                start = prev->next;
            }
            if( k == n){
                end = p;
                tail = p->next;
                break;
            }
            k++;
            p = p->next;
        }
        //说明start是头结点
        if(!prev){
            start = head;
        }
        //终点为null，说明n已经超出列表范围
        if(!end){
            return head;
        }

        //setp3: reverse partial list
        
        //保存当前的头结点指针
        p = start;
        //断开终结点
        end -> next = nullptr;
        ListNode* q = reverse(start);
        if(prev){
            prev -> next = q;
        }else{
            head = end;
        }
        
        //step 4: connect the tail list
        //链接尾部节点
        p->next = tail;

        
        return head;
    }
};

int main(){
    
    Solution s;
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
    ListNode* last = s.reverseBetween(head,2,4);
    while(last){
        cout<<last->val<<endl;
        last = last->next;
    }
    
    
    return 0;
}

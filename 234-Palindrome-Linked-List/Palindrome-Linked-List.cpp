#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

//找到中点，后一半列表翻转后和前一半列表进行比较
//翻转 linked list 只需要O(n)的时间
//一共需要O(4*n)时间
class Solution {
private:
    ListNode *reverseList(ListNode *head){
        ListNode*  second = nullptr;
        ListNode*  first = nullptr;
        while(head){
            //先保存head
            first  = head;
            //head指向下一个节点，维持正常循环
            head = head->next;
            //head下一个节点指向null
            first->next = second;
            //second指向head
            second = first;
        }
        return second;
    }
public:
    bool isPalindrome(ListNode* head) {
        int len = 0;
        ListNode* tail = head;
        //find length of the list
        while(tail){
            len ++;
            tail = tail->next;
        }
        if(len <= 1){
            return true;
        }
        //找到翻转链表的起始位置
        int cut_index = len%2 == 0 ? len/2 : len/2+1;
        tail = head;
        int k =0;
        ListNode* rhead = nullptr;
        while(tail){
            if(k == cut_index){
                rhead = tail;
                break;
            }
            k++;
            tail = tail->next;
        }
        //翻转链表
        rhead = reverseList(rhead);
        
        //比对
        while(rhead&&head){
            if(rhead->val != head->val){
                return false;
            }
            rhead=rhead->next;
            head=head->next;
        }
        return true;
    }
};

int main(){
    Solution s;
    ListNode* node = new ListNode(1);
    node->next = new ListNode(2);
//    node->next->next = new ListNode(3);
//    node->next->next->next = new ListNode(2);
//    node->next->next->next->next = new ListNode(1);
    cout<<s.isPalindrome(node)<<endl;
    return 0;
}

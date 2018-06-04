#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

//翻转 linked list 只需要O(n)的时间
//一共需要O(4*n)时间
class Solution {
private:
    ListNode *reverseList(ListNode *head){
        ListNode* last = nullptr;
        ListNode* tail = head;
        while(tail){
            ListNode* node = new ListNode(tail->val);
            node -> next = last;
            last = node;
            tail = tail->next;
        }
        return last;
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
    node->next->next = new ListNode(3);
    node->next->next->next = new ListNode(2);
    node->next->next->next->next = new ListNode(1);
    return 0;
}
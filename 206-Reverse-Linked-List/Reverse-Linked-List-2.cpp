#include <iostream>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

/*
 迭代法：O(n) + O(1)
 不修改原链表
 1 --> 2 --> 3 --> 4
 loop#1: 1 --> null   |  2-->3-->4
 loop#2: 2 --> 1 --> null | 3-->4
 loop#3: 3 --> 2 --> 1 --> null | 4
 loop#4: 4 --> 3 --> 2 --> 1 --> null |
 */
class Solution
{
  public:
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
};

int main()
{
    Solution s;
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    ListNode* last = s.reverseList(head);
    while(last){
        cout<<last->val<<endl;
        last = last->next;
    }
    return 0;
}
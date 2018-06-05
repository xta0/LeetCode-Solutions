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
 修改原链表
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

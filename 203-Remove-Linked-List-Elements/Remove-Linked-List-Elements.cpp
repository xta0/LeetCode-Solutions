#include <iostream>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution
{
public:
    ListNode *removeElements(ListNode *head, int val){
        //skip duplicated head node
        while(head && head->val == val){
            head = head->next;
        }
        //find node to be deleted
        ListNode* first = head;
        while(first&&first->next){
            if(first -> next ->val == val){
                //move pointer
                first->next = first->next->next;
            }else{
                first = first->next;
            }
        }
        return head;
    }
};
int main()
{
    //[1,1]
    Solution s;
    ListNode* head = new ListNode(1);
    head->next = new ListNode(1);
    ListNode* node = s.removeElements(head, 1);
    while(node){
        cout<<node->val<<endl;
        node = node -> next;
    }
    
    return 0;
}

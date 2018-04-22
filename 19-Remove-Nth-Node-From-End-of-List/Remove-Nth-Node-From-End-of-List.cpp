#include <iostream>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution{
public:
    ListNode *removeNthFromEnd(ListNode *head, int n){
        //length of the list
        int len = 0;
        ListNode *pos = head;
        ListNode *prev = head;
        while (pos){
            pos = pos->next;
            len++;
        }
        ListNode *node_to_be_deleted = NULL;
        int prev_index = len - n;
        if(prev_index < 0){
            return NULL;
        }else if (prev_index == 0){
            //delete head node
            head = head->next;
            return head;
        }else{
            //find prev_node
            int count = 1;
            while(count < prev_index){
                prev = prev->next;
                count++;
            }
            node_to_be_deleted = prev->next;
            if(node_to_be_deleted == NULL){
                //delete tail node
                prev->next = NULL;
            }else{
                prev->next = node_to_be_deleted->next;
            }
            return head;
        }
    };
};

int main()
{
    //test case;
    //[]
    //[1],1
    //[1,2],2
    //[1,2,3,4,5],2
    return 0;
}

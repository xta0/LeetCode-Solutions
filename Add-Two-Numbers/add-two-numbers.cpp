/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution
{
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2){
        
        ListNode* result=NULL, *lastNode=result;
        bool has_carry = false;
        while(l1 != NULL || l2 != NULL){
            int v1 = l1==NULL?0:l1->val;
            int v2 = l2==NULL?0:l2->val;
            int value = v1+v2;
            if(has_carry){
                value += 1;
            }
            if(value >= 10){
                has_carry = true;
                value -= 10;
            }else{
                has_carry = false;
            }
            if(result == NULL){
                result = new ListNode(value);
                lastNode = result;
            }else{
                lastNode->next = new ListNode(value);
                lastNode = lastNode->next;
            }

            if(l1){
                l1 = l1->next;
            }
            if(l2){
                l2 = l2->next;
            }
        }
        if(has_carry){
            lastNode->next = new ListNode(1);
        }
        
        return result;
    }
};


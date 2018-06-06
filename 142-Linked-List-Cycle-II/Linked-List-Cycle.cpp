#include <iostream>
#include <algorithm>
#include <set>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
      //1, detect cycle
      ListNode* fast = head;
      ListNode* slow = head;
      bool isCycle = false;
      while(slow&&fast){
          slow = slow -> next;
          fast = fast -> next;
          if(!fast){
              return NULL;
          }else{
              fast = fast->next;
          } 
          if(fast == slow){
              isCycle = true;
              break;
          }
      }
      //2. 如果成环，另一个新指针entry指向队首，entry和slow每次前进一步，直到和slow相遇
      //需要证明略
      if(!isCycle){
          return nullptr;
      }else{
          ListNode* entry = head;
          while(entry != slow){
              entry = entry->next;
              slow = slow->next;
          }
          return entry;
      }
    }
};

int main(){

    return 0;
}
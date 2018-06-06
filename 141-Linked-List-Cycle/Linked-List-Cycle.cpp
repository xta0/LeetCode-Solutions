#include <iostream>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

//快慢指针追赶
class Solution
{
  public:
    bool hasCycle(ListNode *head)
    {
        if (head == NULL){
            return false;
        }
        ListNode *fast = head;
        ListNode *slow = head;
        bool isCycle = false;
        while (slow && fast){
            slow = slow->next;
            fast = fast->next;
            if (!fast){
                return false;
            }else{
                fast = fast->next;
            }
            if (fast == slow){
                isCycle = true;
                break;
            }
        }
        return isCycle;
    }
};

int main()
{

    return 0;
}
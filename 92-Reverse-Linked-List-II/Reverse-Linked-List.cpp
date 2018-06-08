#include <iostream>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if(!head){
            return head;
        }
        if(m == n || n == 1){
            return head;
        }        
        
    }
};

int main(){




    return 0;
}
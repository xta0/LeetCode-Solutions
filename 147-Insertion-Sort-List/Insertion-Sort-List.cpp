#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
private:
    ListNode* moveto(ListNode* head, int n ){
        
    }
public:
    ListNode* insertionSortList(ListNode* head) {
        int len = 0;
        ListNode* p = head;
        while(p){
            len ++;
            p = p->next;
        }
        p = head;
        for(int i =1; i<len; ++i){
            
        }


        return head;
    }
};

int main(){




    return 0;
}
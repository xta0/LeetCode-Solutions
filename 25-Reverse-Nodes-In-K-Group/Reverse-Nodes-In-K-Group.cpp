#include <iostream>
#include <stack>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* pos = head;
        ListNode* prev = head;
        int count = 1;
        stack<int> ss;
        while(pos){
            ss.push(pos->val);
            if(count % k == 0){
                while(!ss.empty()){
                    int val = ss.top();
                    prev->val = val;
                    ss.pop();
                    prev = prev->next;
                }
                count = 0;
            }
            count++;
            pos = pos -> next;
        }
        return head;
    }
};
int main(){
    return 0;
}

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        
        unordered_map<int, ListNode* > cache;
        //cache lists head 
        for(int i=0;i<lists.size();++i){
            ListNode* head = lists[i];
            cache[i] = head;
        }
        ListNode* head = NULL;
        ListNode* pos = NULL;
        // vector<ListNode* > candicates;
        int min_val =1<<30;
        while(true){
            
            int min_index = -1;
            bool finished = false;
            for(auto it: cache){
                if(it->second != NULL){
                    int val = it->second->val; 
                    if(val < min_val){
                        min_val = val;
                        min_index = it->first;
                    }
                }
            }
            if(finished){
                break;
            }else{
                ListNode* node = new ListNode(min_val);
                if(head){
                    pos ->next =  node;
                }else{
                    head = new ListNode(min_val);
                    pos = head;
                }
                //update cache
                ListNode* update_node =  cache[min_index];
                update_node = update_node -> next;
            }
        }           
        return head;
    }
};

int main(){




    return 0;
}
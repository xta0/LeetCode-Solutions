#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <unordered_set>
#include <unordered_map>
using namespace std;

/*
Time: O(n)
Space: O(1)
*/
class Solution {
public:
    int shortestWordDistance(vector<string>& words, string word1, string word2) {
        int res = words.size();
        if(word1 == word2){
            int p = -1;
            for(int i=0; i<words.size();i++){
                string w = words[i];
                if(w == word1){
                    if(p!=-1){
                        res = min(res,i-p);
                    }
                    p = i;    
                }
            }
        }else{
            int p1 = -1; int p2 = -1;
            for(int i=0;i<words.size();i++){
                string w = words[i];
                if(word1 == w){
                    p1 = i;
                }
                if(word2 == w){
                    p2 = i;
                }
                if(p1!=-1&&p2!=-1){
                    res = min(res,abs(p1-p2));
              }
            }
        }
        return res;
        
    }
};
int main(){




    return 0;
}
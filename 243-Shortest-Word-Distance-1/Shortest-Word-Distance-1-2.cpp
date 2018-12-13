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
    int shortestDistance(vector<string>& words, string word1, string word2) {
        int p1 = -1; int p2 = -1;
        int res = words.size();
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
        return res;
    }
};

int main(){




    return 0;
}
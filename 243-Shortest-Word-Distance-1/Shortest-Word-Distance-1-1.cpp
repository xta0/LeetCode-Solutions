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
Solution: Hashmap
Time: O(n)
Space: O(n)
*/
class Solution {
public:
    int shortestDistance(vector<string>& words, string word1, string word2) {
        
        unordered_map<string,int> um;
        int res = words.size();
        for(int i=0;i<words.size();i++){
            string word = words[i];
            if(word == word1 && um.count(word2)){   
                res = min(res, abs(i-um[word2]));
            }
            
            if(word == word2 && um.count(word1)){
                res = min(res, abs(i-um[word1]));
            }
            um[word] = i;
        }
        return res;
    }
};

int main(){




    return 0;
}
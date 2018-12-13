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
Time: O(n1*n2)
Space: O(n)
*/
class Solution {
public:
    int shortestWordDistance(vector<string>& words, string word1, string word2) {
        unordered_map<string, vector<int>> um;
        for(int i=0;i<words.size();i++){
            string w = words[i];
            um[w].push_back(i);
        }
        auto v1 = um[word1];
        auto v2 = um[word2];
        
        int res = words.size();
        if(word1 == word2){
            for(int i=0;i<v1.size();i++){
                for(int j=i+1;j<v1.size();j++){
                    res = min(res, abs(v1[i]-v1[j]));
                }
            }
        }else{
            for(int i=0;i<v1.size();i++){
                for(int j=0;j<v2.size();j++){
                    res = min(res,abs(v1[i]-v2[j]));
                }
            }
        }
        return res;
      
    }
};
int main(){




    return 0;
}
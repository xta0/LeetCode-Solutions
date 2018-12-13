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
class WordDistance {
    unordered_map<string, vector<int>> um;
public:
    WordDistance(vector<string> words) {
        for(int i=0;i<words.size();i++){
            string word = words[i];
            um[word].push_back(i);
        }
    }
    
    int shortest(string word1, string word2) {
        auto v1 = um[word1];
        auto v2 = um[word2];
        int res = INT_MAX;
        //find the minimum distance
        for(auto p1:v1){
            for(auto p2:v2){
                res = min(res,abs(p1-p2));
            }
        }
        return res;
    }
};

int main(){




    return 0;
}
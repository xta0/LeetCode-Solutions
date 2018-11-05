#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <queue>
#include <unordered_set>
#include <unordered_map>
#include <functional>
#include <numeric>

using namespace std;

class Solution {
public:
    int numJewelsInStones(string J, string S) {
        unordered_set<char> us(J.begin(),J.end());
        int ans = 0;
        for(auto c : S){
            if(us.count(c)){
                ans++;
            }
        }
        return ans;
    }
};

int main(){
    Solution s;
    s.numJewelsInStones("aA", "aAAbbbb");
}

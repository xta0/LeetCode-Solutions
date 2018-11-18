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

class Solution {
public:
    int repeatedStringMatch(string A, string B) {
        unordered_set<char> us(A.begin(),A.end());
        for(auto c:B){
            if(!us.count(c)){
                return -1;
            }
        }
        int count = 1;
        while(true){
            if(A.find(B) != std::string::npos){
                break;
            }
            count++;
            A = A+A;
        }
        return count;
    }
};

int main(){
    Solution s;
    cout<<s.repeatedStringMatch("abc","cabcabca")<<endl;




    return 0;
}
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
Solution: None
Time: O(N)
Space: O(1)
*/
class Solution {
public:
    int titleToNumber(string s) {
        if(s.empty()){
            return 0;
        }
        int i = 0;
        int sum = 0;
        while( i< s.size()){
            char c = s[i];
            sum = sum*26 + (c-'A'+1);
            i++;
        }
        return sum;
    }
};
int main(){
    Solution s;
    cout<<s.titleToNumber("AAA")<<endl;

    return 0;
}

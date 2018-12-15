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
    string convertToTitle(int n) {
        string res = "";
        int r = -1;
        while(n >= 1){
            r = (n-1)%26;
            n = (n-1)/26;
            res = (char)('A'+r) + res;
        }
        return res;
    }
};
int main(){
    Solution s;
    cout<<s.convertToTitle(703)<<endl;
    
    
    
    
    return 0;
}

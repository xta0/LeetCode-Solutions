#include <string>
#include <iostream>
using namespace std;

/*
Solution: Brute Force
Time: O(N)
Space:O(1)
*/
class Solution {
public:
    int strStr(string haystack, string needle) {
        if(needle.size() > haystack.size()){
            return -1;
        }
        if(haystack.empty() && needle.empty()){
            return 0;
        }
        for(int i=0;i<haystack.size();i++){
            for(int j=i;j<haystack.size();j++){
                if(j+needle.size() > haystack.size()){
                    return -1;
                }
                if(needle == haystack.substr(j,needle.size())){
                    return j;
                }
            }
        }
        return -1;
        
    }
};

int main(){
    return 0;
}

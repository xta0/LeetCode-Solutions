#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    string reverseString(string s) {
        int l = 0, r = s.length() -1;
        while(l <= r){
            swap(s[l],s[r]);
            l++;
            r--;
        }
        return s;
        
    }
};

int main(){




    return 0;
}
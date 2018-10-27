#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    bool helper(string& s, int l, int r){
        while(l<r){
            if(s[l] == s[r]){
                l++;
                r--;
            }else{
                return false;
            }
        }
        return true;
    }
    bool validPalindrome(string s) {
        int l=0, r=s.size()-1;
        while(l<r){
            if(s[l]==s[r]){
                l++;
                r--;
            }else{
                //check two ranges [l,r) & (l,r]
                return helper(s,l, r-1) ? true:helper(s, l+1, r);  
            }
        }
        return true;
    }
};

int main(){




    return 0;
}
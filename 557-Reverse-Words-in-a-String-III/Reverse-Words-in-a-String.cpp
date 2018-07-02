#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
    void reverseString(string& s, int l, int r){
        while(l<=r){
            swap(s[l],s[r]);
            l++;
            r--;
        }
    }
public:
    string reverseWords(string s) {
        if(!s.length()){
            return "";
        }
        int l=0,r=0;
        while(r < s.length()){
            if(r == ' '){
                reverseString(s,l,r-1);
                r++;
                l=r;
            }else{
                r++;
            }
        }
        reverseString(s,l,r-1);
        return s;
    }
};

int main(){
    Solution s;
    cout<<s.reverseWords("Let's take LeetCode contest")<<endl;



    return 0;
}
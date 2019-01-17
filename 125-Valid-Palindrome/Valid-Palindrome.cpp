#include <iostream>
#include <string>
#include <cctype>

using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        if(s.empty()){
            return true;
        }
        int l=0;
        int r = s.size()-1;
        while(l<=r){
            char cl = tolower(s[l]);
            char cr = tolower(s[r]);
            if(!isalnum(cl) || isspace(cl)){
                l++;
                continue;
            }
            if(!isalnum(cr) || isspace(cr)){
                r--;
                continue;
            }
            if(cl == cr){
                l++;
                r--;
            }else{
                return false;
            }
        }
        
        return true;
    }
};



int main(){
    Solution s;
    cout<<s.isPalindrome("A man, a plan, a canal: Panama")<<endl;
    cout<<s.isPalindrome("race a car")<<endl;
    cout<<s.isPalindrome("0P")<<endl;



    return 0;
}
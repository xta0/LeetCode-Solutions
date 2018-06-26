#include <iostream>
#include <vector>
#include <array>

using namespace std;

class Solution {
public:
    bool isVowel(char c){
        c = tolower(c);
        if( c=='a' || c=='e'  || c=='i' || c=='o' || c=='u'){
            return true;
        }else{
            return false;
        }
    }
    string reverseVowels(string s) {
        int l = 0, r = (int)s.length() -1;
        while(l<=r){
            while( !isVowel(s[l]) && l<=r){
                l++;
            }
            while(!isVowel(s[r]) && l<=r){
                r--;
            }
            if(l<=r){
                swap(s[l],s[r]);
                l++;
                r--;
            }
        }
        return s;
    }
};

int main(){
   
    return 0;
}

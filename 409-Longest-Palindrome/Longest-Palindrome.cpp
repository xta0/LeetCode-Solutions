#include <iostream>
#include <string>
#include <map>
#include <vector>
using namespace std;

//中心扩散法
//O(n^2)
class Solution {
public:
    string palindrome(string& s, int l, int r){
        while(l>=0 && r<s.size()){
            if(s[l] == s[r] ){
                l--;
                r++;
            }else{
                break;         
            }
        }
        l++;r--;
        return s.substr(l,r-l+1);
    }
    string longestPalindrome(string s) {
        if(s.size() <= 1){
            return s;
        }
        string smax="";
        for(int i=0;i<s.size();i++){
            //中心为奇数
            string s1 = palindrome(s,i-1,i+1);
            if(s1.size() > smax.size()){
                smax = s1;
            }
            //中心为奇数
            string s2 = palindrome(s,i,i+1);
            if(s2.size() > smax.size()){
                smax= s2;
            }            
        }
        return smax;
    }
};
int main(){
    Solution s;
    cout<<s.longestPalindrome("aaaAaaaa")<<endl;
    return 0;
}

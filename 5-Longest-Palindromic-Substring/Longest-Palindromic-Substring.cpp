#include <iostream>
#include <string>
#include <algorithm>    // std::max

using namespace std;

//中心扩散 - O(n^2)
class Solution {
private:
    string helper(string& ss, int left , int right){
        while (left >0 && right < ss.length()-1) {
            if(ss[left-1]==ss[right+1]){
                left --;
                right ++;
            }else{
                break;
            }
        }
        return ss.substr(left,right-left+1);
    }
public:
    string longestPalindrome(string s) {
        if(s.length() == 0 || s.length() == 1){
            return s;
        }
        string last(""),ret("");
        int k = 0;
        for(int i=0;i<s.length(); ++i){
            //剪枝
            if(s.length() - 1 <= ret.length()/2){
                 break;
            }
            //确定右边界
            k = i;
            while(s[k] == s[k+1]){
                ++k;
            }
            last = helper(s,i, k);
            if(last.length() > ret.length()){
                ret = last;
            }
        }
        return ret;
    }
};

int main(){
    
    Solution s;
    cout<<s.longestPalindrome("")<<endl;
    cout<<s.longestPalindrome("x")<<endl;
    cout<<s.longestPalindrome("aa")<<endl;
    cout<<s.longestPalindrome("cbbd")<<endl;
    cout<<s.longestPalindrome("babad")<<endl;
    cout<<s.longestPalindrome("abxba")<<endl;
    cout<<s.longestPalindrome("abbaabba")<<endl;
    cout<<s.longestPalindrome("abbaabxbax")<<endl;
    
    
    return 0;
}

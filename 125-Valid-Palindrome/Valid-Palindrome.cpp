#include <iostream>
#include <string>
#include <cctype>

using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        string ss;
        for(auto c : s){
            if(std::isalnum(c)){
                c = isalpha(c) ? std::tolower(c,std::locale()):c;
                ss.push_back(c);
            }
        }
        int left = 0; int right = ss.length()-1;
        while(left <= right){
            if(ss[left] == ss[right]){
                left ++;
                right--;
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
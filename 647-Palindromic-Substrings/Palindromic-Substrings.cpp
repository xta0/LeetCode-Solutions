#include <iostream>
#include <string>
#include <vector>
using namespace std;

/*
 中心扩散 O(n^2)
 */
class Solution {
private:
    int countPalindrome(int l, int r, string& s, int count){
        while(l>=0 && r < s.size()){
            if(s[l--] == s[r++]){
                count ++;
            }
        }
        return count;
    }
public:
    int countSubstrings(string s) {
        
        int count = 0;
        for(int i =0; i<s.length();++i){
            //中心为奇数
            count += countPalindrome(i-1,i+1,s,1);
            //中心为偶数
            count += countPalindrome(i,i+1,s,0);
        }

        return count;
    }
};

int main(){
    Solution s;
    cout<<s.countSubstrings("aaa")<<endl; //6
    
    return 0;
}

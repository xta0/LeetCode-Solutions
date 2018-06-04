#include <iostream>
#include <string>
#include <map>
#include <vector>
using namespace std;

class Solution {
public:
    int longestPalindrome(string s) {
        map<char,int> dictionary;
        vector<int> vec(53,0);
        for(auto c:s){
            if(c >= 'a'){
                vec[c-'a'+26] ++;
            }
            else{
                vec[c-'A'] ++;
            }
        }
        int count = 0;
        bool flag = false;
        for(auto cnt : vec){
            if(cnt % 2 == 0){
                count += cnt;
            }else{
                flag = true;
                count += cnt-1;
            }
        }
        if(flag){
            count += 1;
        }
        return count;
    }
};

int main(){
    Solution s;
    cout<<s.longestPalindrome("aaaAaaaa")<<endl;
    return 0;
}

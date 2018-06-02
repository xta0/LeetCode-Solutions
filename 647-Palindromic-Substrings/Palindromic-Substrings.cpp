#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int countSubstrings(string s) {
        //预处理
        for(int i=0; i<s.length();i++){
            s.insert(i,"*");
        }        
        cout<<s<<endl;
    }
    return -1;
};

int main(){
    Solution s;
    s.countSubstrings("abc");

    return 0;
}
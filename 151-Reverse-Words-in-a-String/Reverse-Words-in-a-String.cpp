#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    void reverseWords(string &s) {
        //lamda function
        auto reverseWord = [](string& s, int l, int r){
            while(l < r){
                swap(s[l],s[r]);
                l++;
                r--;
            }
        };
        
        //step1: reverse the whole sentence
        int l=0, r=0;
        reverseWord(s,0,(int)s.length()-1);
        
        //step2: reverse each word
        while(s.begin()+r != s.end()){
            if(s[r] == ' '){
                reverseWord(s,l,r-1);
                r++;
                //step2.1: erase whilte spaces
                while(s[r] == ' '){
                    s.erase(s.begin()+r);
                }
                l = r;
            }else{
                r++;
            }
        }
        reverseWord(s,l,r-1);
        
        //step3: clean the front or back white-space if necessary.
        if(*s.begin() == ' '){
            s.erase(s.begin());
        }
        if(*(s.end()-1) == ' '){
            s.erase(s.end()-1);
        }
    }
};


int main(){
    string ss = "         a      b              ";
    Solution s;
    s.reverseWords(ss);
    cout<<"|"<<ss<<"|";
    
    
    
    return 0;
}

#include <iostream>
#include <vector>
#include <string>
using namespace std;


/*
1. 从左向右扫描，把所有*都看成 '('，看是否能闭合所有 ’）'，如果能，至少说明’）‘可以全部被闭合，但不能保证"("可以全部被闭合
2. 从右向左再扫一次，把""*"看成 ")"看是否能够闭合所欲 "("，如果能，则说明左右括号都能闭合
*/
class Solution {
public:
    //检车是否所有右括号可以闭合,返回闭合右括号的数量
    int scanFromLeft2Right(const string& s){
        int l=0;
        int r = 0;
        for(int i=0; i<s.size(); i++){
            char c = s[i];
            if( c == '(' || c=='*' ){
                l++;
            }else {
                if(l > 0){
                    l--;
                }else{
                    r++;
                }
            }
        }
        return r;
    }
    int scanFromRight2Left(const string& s){
        int l=0;
        int r = 0;
        //检车是否所有右括号可以闭合
        for(int i=s.size()-1; i>=0; i--){
            char c = s[i];
            if( c == ')' || c=='*' ){
                r++;
            }else {
                if(r > 0){
                    r--;
                }else{
                    l++;
                }
            }
        }
        return l;
    }
    bool checkValidString(string s) {
        int r = scanFromLeft2Right(s);
        int l = scanFromRight2Left(s);
        if(r > 0 || l>0){
            return false;
        }
        return true;
    }
};

int main(){




    return 0;
}
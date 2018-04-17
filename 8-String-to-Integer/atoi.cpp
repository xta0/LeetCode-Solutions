#include <iostream>
#include <algorithm>
#include <string>
#include <cctype>
#include <cmath>
using namespace std;

class Solution {
public:
    int myAtoi(string str) {
        
        int result = 0;
        string ss("");
        size_t pos = str.find_first_not_of(' ');
        if( pos != string::npos ){
            ss = str.substr(pos);
        }
        if(isdigit(ss[0]) || ss[0] == '-' || ss[0] == '+'){
            bool minus = ss[0] == '-';
            if(ss[0] == '-' || ss[0] == '+'){
                ss = ss.substr(1);
            }
            size_t len = 0;
            while(isdigit(ss[len])){
                len++;
            }
            ss = ss.substr(0,len);
            long temp = 0;
            for(int i= (int)ss.length()-1; i>=0; i--){
                int x = ss[i] - '0';
                temp = temp + x * pow(10,(int)ss.length()-1-i);
                if(temp > INT_MAX || -temp < INT_MIN){
                    result = minus?INT_MIN : INT_MAX ;
                    break;
                }else{
                    result = (int)temp;
                }
            }
            if(minus){
                result = -result;
            }
            return result;
            
        }else{
            return 0;
        }
    }
};

int main(){
    
    Solution s;
   cout<<s.myAtoi("0")<<endl;
   cout<<s.myAtoi("42")<<endl;
   cout<<s.myAtoi("-42")<<endl;
   cout<<s.myAtoi("   -42")<<endl;
   cout<<s.myAtoi("4193 with words")<<endl;
   cout<<s.myAtoi("-91283472332")<<endl;
   cout<<s.myAtoi("91283472332")<<endl;
 
    return 0;
}

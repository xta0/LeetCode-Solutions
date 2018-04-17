#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string intToRoman(int num) {
        string roman("");
        string ss = to_string(num);
        std::reverse(ss.begin(), ss.end());
        for(int i=0; i<ss.length();++i){
            char c = ss[i];
            int x = atoi(&c);
            string tmp = this->symbol(x,i);
            roman.insert(0, tmp);
            
        }
        return roman;
    }
private:
    string symbol(int x, int i){
        string result("");
        if (x == 0){
            result = "";
        }
        else if(x > 0 && x < 4){
            for(int j = 0; j<x; j++){
                if(i == 0){
                    result += "I";
                }else if(i==1){
                    result += "X";
                }else if(i==2){
                    result += "C";
                }else{
                    result += "M";
                }
            }
        }else if( x == 4 ){
            if(i == 0){
                result = "IV";
            }else if(i==1){
                result = "XL";
            }else if(i==2){
                result = "CD";
            }
        }else if( x== 5){
            if(i == 0){
                result = "V";
            }else if(i==1){
                result = "L";
            }else if(i==2){
                result = "D";
            }else{
                result = "";
            }
        }else if(x > 5 && x < 9){
            result = symbol(5,i);
            for(int j = 0; j< x - 5; j++){
                if(i == 0){
                    result += "I";
                }else if(i==1){
                    result += "X";
                }else if(i==2){
                    result += "C";
                }else{
                    result += "M";
                }
            }
        }else{
            //x == 9
            if(i==0){
                result = "IX";
            }else if(i==1){
                result = "XC";
            }else if(i == 2){
                result = "CM";
            }else{
                result = "";
            }
        }
        return result;
    }
};

int main(){
    Solution s;
    cout<<s.intToRoman(3)<<endl;
    cout<<s.intToRoman(4)<<endl;
    cout<<s.intToRoman(9)<<endl;
    cout<<s.intToRoman(58)<<endl;
    cout<<s.intToRoman(1994)<<endl;
    
    
    
    return 0;
}

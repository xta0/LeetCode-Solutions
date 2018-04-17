#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string intToRoman(int num) {
        string ss;
        const string romans[4][10] = {
            {"","I","II","III","IV","V","VI","VII","VIII","IX"},
            {"","X","XX","XXX","XL","L","LX","LXX","LXXX","XC"},
            {"","C","CC","CCC","CD","D","DC","DCC","DCCC","CM"},
            {"","M","MM","MMM"},
        };
        return romans[3][num/1000%10]+romans[2][num/100%10]+romans[1][num/10%10]+romans[0][num%100];
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

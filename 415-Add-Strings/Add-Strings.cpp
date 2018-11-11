#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
using namespace std;


class Solution {
public:
    char addTwoChars(char c1, char c2, bool& carry){
        int n1 = c1-'0';
        int n2 = c2-'0';
        int sum = carry ? n1+n2+1:n1+n2;
        if(sum >= 10){
            sum -= 10;
            carry = true;
        }else{
            carry = false;
        }
        return sum + '0';
    }
    string addStrings(string num1, string num2) {
        int sz1 = num1.size();
        int sz2 = num2.size();
        //add padding zeros
        if(sz1 == 0){
            return num2;
        }else if(sz2 == 0){
            return num1;
        }
        if(sz1 > sz2){
            num2.insert(num2.begin(), sz1-sz2, '0');
        }else if(sz2 > sz1){
            num1.insert(num1.begin(), sz2-sz1,'0');
        }
        int i = num1.size()-1;
        string ans = "";
        bool carry = false;
        while(i>=0){
            char x = addTwoChars(num1[i],num2[i],carry);
            ans.insert(ans.begin(),x);
            i--;
        }
        if(carry){
            ans.insert(ans.begin(),'1');
        }
        return ans;
        
    }
};
int main(){
    Solution s;
    cout<<s.addStrings("9133", "0")<<endl;
    
    
    
    return 0;
}

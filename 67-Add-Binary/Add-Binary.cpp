#include <iostream>
#include <string>
using namespace std;

class Solution {
    char add(char c1, char c2, bool& carry){
        int d1 = c1-'0';
        int d2 = c2-'0';
        int d = d1^d2;
        bool carry1 = d1 & d2;
        bool carry2 = false;
        if(carry){
            carry2 = d&1;
            d = d^1;
        }
        carry = carry1 || carry2;
        return d+'0';
        
    }
public:
    string addBinary(string a, string b) {
        int sz1 = a.size();
        int sz2 = b.size();
        if(!sz1){
            return b;
        }
        if(!sz2){
            return a;
        }
        //add padding zeros
        if(sz1 > sz2){
            b.insert(b.begin(),sz1-sz2,'0');
        }
        if(sz2>sz1){
            a.insert(a.begin(),sz2-sz1,'0');
        }
        int i = a.size()-1;
        bool carry=false;;
        string res="";
        while(i>=0){
            res.insert(res.begin(),add(a[i],b[i],carry));
            i--;
        }
        if(carry){
            res.insert(res.begin(),'1');
        }
        return res;
    }
};
int main(){
    
    Solution s;
    cout<<s.addBinary("11","1")<<endl; //100
    cout<<s.addBinary("1010","1011")<<endl; //10101
    
    return 0;
}

#include <iostream>
#include <string>
using namespace std;

class Solution {
private:
    //逐位累加，直到某个string为空，返回进位
    void add(string& a, string& b, string& ret, bool& carry ){
        if(a.size() == 0 || b.size() == 0){
            return ;
        }
        int x = a.back() == '0'? 0:1; a.pop_back();
        int y = b.back() == '0'? 0:1; b.pop_back();
        int z = x^y;
        bool carry1 = x&y;
        bool carry2 = false;
        int sum = z;
        if(carry){
            sum = z^1;
            carry2 = z&1;
        }
        ret = sum==0?("0"+ret):("1"+ret);
        carry = carry1 || carry2;
        //递归
        add(a,b,ret,carry);
    }
public:
    string addBinary(string a, string b) {
        string ret="";
        bool carry = false;
        add(a,b,ret,carry);
        //处理剩余字符串，主要考虑是否有进位
        string str = a.size()>0?a:b;
        for(int i = (int)str.size()-1; i>=0; i--){
            int x = str[i] =='0'?0:1;
            int sum = x;
            if(carry){
                sum = x^1;
                carry = x&1;
            }
            ret=sum==0?"0"+ret:"1"+ret;
        }
        if(carry){
            ret = "1"+ret;
        }
        return ret;
    }
};

int main(){
    
    Solution s;
    cout<<s.addBinary("11","1")<<endl; //100
    cout<<s.addBinary("1010","1011")<<endl; //10101
    
    return 0;
}

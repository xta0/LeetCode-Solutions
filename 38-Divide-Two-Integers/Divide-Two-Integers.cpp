#include <iostream>
using namespace std;

class Solution {
public:
    int add(int a, int b)
    {
        int partialSum, carry;
        do{
            partialSum = a ^ b;
            carry = (a & b) << 1;
            a = partialSum;
            b = carry; 
        } while (carry != 0);
        return partialSum;
    }
    int substract(int a, int b){
        return add(a,add(~b,1));
    }
    int divide(int a, int b) {
        long long  dividend = a < 0 ? add(~a, 1) : a; //取绝对值
        long long  divisor = b < 0 ? add(~b, 1) : b; //取绝对值
        if(dividend > INT_MAX) {
            return INT_MAX;
        }
        int remainder = dividend;
        int result = 0;
        while(remainder >= divisor){
            remainder = substract(remainder,divisor);
            result = add(result,1);
        }
        if((a^b)<0){
            result = add(~result,1);
        }
        if(result > INT_MAX || result < -INT_MAX){
            return INT_MAX;
        }else{
            return result;
        }
    }
};

int main(){

    Solution s;
    cout<<s.divide(10,3)<<endl;
    cout<<s.divide(7,-3)<<endl;
    cout<<s.divide(-2147483648,-1)<<endl;


    return 0;
}
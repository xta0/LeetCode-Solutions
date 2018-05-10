#include <iostream>
#include <cmath>
using namespace std;


class Solution {
public:sss
    long long  add(long long  a, long long b)
    {
        long long  partialSum, carry;
        do{
            partialSum = a ^ b;
            carry = (a & b) << 1;
            a = partialSum;
            b = carry;
        } while (carry != 0);
        return partialSum;
    }
    long long substract(long long a, long long b){
        return add(a,add(~b,1));
    }
    int divide(int a, int b) {
        int sign = ((a <0) ^ (b< 0)) ? -1 : 1;
        long long dividend  = labs(a);
        long long divisor = labs(b);
        long long tmp = 0;
        long long  result = 0;
        for(int i=31; i>=0; i--){
            tmp  = divisor << i; //divisor不变，tmp不断变小，int类型放置左移溢出
            if(dividend >= tmp){
                result = add(result,1UL<<i);
                dividend = (int)substract((int)dividend,(int)tmp);
            }
        }

        result = sign == 1 ? result : -result;
        if(result > INT_MAX || result < INT_MIN ){
            return INT_MAX;
        }else{
            return (int)result;
        }
    }
};
int main()
{
    Solution s;
//    cout<<s.divide(15, 3)<<endl;
    cout<<s.divide(-2147483648, -1)<<endl;
    cout<<s.divide(-2147483648,1)<<endl;
    
    return 0;
}

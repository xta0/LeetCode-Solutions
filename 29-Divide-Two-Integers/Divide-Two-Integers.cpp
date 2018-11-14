#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <unordered_set>
#include <unordered_map>
using namespace std;

class Solution {
    //正数除法
    int helper(int dividend, int divisor){
        if(dividend == 0 || dividend<divisor){
            return 0;
        }
        if(divisor == 1 ){
            return dividend;
        }
        if(dividend == divisor){
            return 1;
        }

        int q = 1; int tmp = divisor;
        while(tmp < dividend){
            tmp = tmp<<1;
            q = q<<1;
        }
        //除数比被除数大
        if(tmp > divisor){
            tmp = tmp>>1;
            q = q>>1;
            return q+helper(dividend-tmp,divisor);
        }else{
            return q;
        }
    }
public:
    int divide(int dividend, int divisor) {
       if(dividend < 0 && divisor < 0){
           return helper(abs(dividend),abs(divisor));
       }else if(dividend < 0 || divisor<0){
           return -helper(abs(dividend),abs(divisor));
       }else{
           return helper(dividend,divisor);
       }
    }
};

int main(){




    return 0;
}
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
    long long  helper(long long dividend, long long divisor){
        if(dividend == 0 || dividend<divisor){
            return 0;
        }
        if(divisor == 1 ){
            return dividend;
        }
        if(dividend == divisor){
            return 1;
        }
        
        long long  q = 1; long long tmp = divisor;
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
        long long x = (long long)dividend;
        long long y = (long long)divisor;
        long long result = 0;
        if(x < 0 && y < 0){
            result =  helper(-x,-y);
        }else if( (x < 0 && y>0) || (x>0&&y<0) ){
            result =  -helper(x,-y);
        }else{
            result =  helper(x,y);
        }
        if(result >= INT_MAX || result < INT_MIN){
            return INT_MAX;
        }else{
            return (int)result;
        }
    }
};
int main(){
    Solution s;
    cout<<s.divide(-7, 3)<<endl;

    return 0;
}

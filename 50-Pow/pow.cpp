#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    double myPow(double x, int n) {
        if(n==0){
            return 1;
        }
        if(n == 1){
            return x;
        }
        double y = myPow(x, n/2);
        //奇数
        if(n%2){
            return n<0? 1.0/x*y*y : x*y*y;
        }else{
            return y*y;
        }
        
    }
};


int main(){
   Solution s;
   cout<<s.myPow(2.000, INT_MIN)<<endl;
    return 0;
}

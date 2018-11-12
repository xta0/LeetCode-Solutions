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

//二分法
// m^2 > x; 找到 m，范围在(0,x]中间

class Solution {
public:
    int mySqrt(int x) {
        if(x == 0){
            return 0;
        }
        if(x==1){
            return 1;
        }
        
        long l = 1; 
        long r = x;
        while(l<=r){
            long m = l+(r-l)/2;
            if( m*m <= x ){
                if(m*m == x || (m+1)*(m+1) > x){ //注意(m+1)^2可能发生溢出，用long声明
                    return m;
                }else{
                    l = m+1;
                }
            }else{
                r = m-1;
            }
        }
        return -1;
        
    }
};
int main(){




    return 0;
}
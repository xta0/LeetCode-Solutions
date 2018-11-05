#include <iostream>
#include <vector>
#include <string>
#include <cmath>
using namespace std;

//筛选法    
//https://zh.wikipedia.org/wiki/%E5%9F%83%E6%8B%89%E6%89%98%E6%96%AF%E7%89%B9%E5%B0%BC%E7%AD%9B%E6%B3%95
class Solution {
public:
    int countPrimes(int n) {
        if( n <= 2){
            return 0;
        }
        vector<bool> flags(n,true);
        flags[0] = flags[1] = 0;
        //标记素数的倍数，素数从2开始
        for(long i=2; i<=sqrt(n);i++){
            if(flags[i]){
                for(int j=i*i; j<n; j=j+i){
                    flags[j] = false;
                }
            }
        }
        int count = 0;
        for(int i=0;i<flags.size();i++){
            if(flags[i] == true){
                count ++;
            }
        }
        return count;
     
    }
};

int main(){




    return 0;
}
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

//使用定义
//每次取余数和商
class Solution {
public:
    int hammingWeight(uint32_t n) {
        int x = 0; 
        int count = 0;
        while(true){
            x = n%2;
            n = n/2;
            if(x == 1){
                count ++;
            }
            if(n==0){
                break;
            }
        }
        return count;
    }
};

int main(){




    return 0;
}
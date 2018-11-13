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

//使用位运算
//时间复杂度:O(number of 1)
class Solution {
public:
    int hammingWeight(uint32_t n) {
        int count = 0;
        while(n!=0){
            count++;
            n = n&(n-1); //去掉n的二进制最后一个1
        }
        return count;
    }
};

int main(){




    return 0;
}
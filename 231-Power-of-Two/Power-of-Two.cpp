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

//位运算
//如果x是2的n次幂，那么x>=1 且二进制有且仅有一个1可得到 x&(x-1)结果一定为0
class Solution {
public:
    bool isPowerOfTwo(int n) {
        return n >= 1 && !(n&(n-1));
    }
};
int main(){




    return 0;
}
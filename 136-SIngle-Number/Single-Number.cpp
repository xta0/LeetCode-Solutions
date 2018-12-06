#include <iostream>
#include <vector>
using namespace std;

//使用XOR，两个相同的数XOR后为0
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ret = 0;
        for(auto x:nums){
            ret = ret^x;
        } 
        return ret;
    }
};

int main(){




    return 0;
}
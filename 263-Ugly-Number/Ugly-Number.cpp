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
    bool helper(int num, set<int>& uns){
        if(num == 1){
            return true;
        }
        for(auto x:uns){
            if(num%x==0){
                //满足条件
                return helper(num/x,uns);
            }
        }
        return false;
        
    }
public:
    bool isUgly(int num) {
        if(num==0){
            return false;
        }
        set<int> uns = {2,3,5};
        return helper(num,uns);
        
    }
};

int main(){




    return 0;
}
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <unordered_map>
#include <numeric>

using namespace std;

class Solution {
public:
    int missingNumber(vector<int>& nums) {        

        int sum1 = std::accumulate(nums.begin(),nums.end(),0);
        int n = nums.size()+1;
        int sum2 = (n-1)*(n)/2;
        
        return sum2-sum1;
    }
};

int main(){




    return 0;
}
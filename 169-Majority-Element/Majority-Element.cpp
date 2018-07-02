#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int> bucket;
        for(auto x:nums){
            bucket[x]++;
            if(bucket[x] > nums.size()/2){
                return x;
            }
        } 
        return -1;
    }
};

int main(){




    return 0;
}
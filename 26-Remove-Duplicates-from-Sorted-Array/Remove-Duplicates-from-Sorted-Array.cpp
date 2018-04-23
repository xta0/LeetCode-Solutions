#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        unordered_map<int,bool> cache;
        auto itor = nums.begin();
        for(;itor != nums.end(); ++itor){
            int x = *itor;
            if(cache.find(x) == cache.end()){
                cache[x] = true;
            }else{
                //remove element
                nums.erase(itor);
                itor--;
            }
        }
        return nums.size();
    }
};

int main(){

}

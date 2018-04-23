#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        auto itor = nums.begin();
        for(;itor!=nums.end();++itor){
            if(*itor==val){
                nums.erase(itor);
                itor--;
            }
        }
        return nums.size();
    }
};

int main(){




    return 0;
}
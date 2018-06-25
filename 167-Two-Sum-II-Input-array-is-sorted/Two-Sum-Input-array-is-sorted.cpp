#include <iostream>
#include <vector>
#include <string>
using namespace std;

//数组有序 -> 首尾指针有序移动
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        if(numbers.size() <= 1){
            return {};
        }
        decltype(numbers.size()) sz = numbers.size();
        if(target > (numbers[sz-1] + numbers[sz-2])){
            return {};
        }
        vector<int> ret;
        int left = 0, right = sz-1;
        while(left < right){
            if(numbers[left] + numbers[right] > target){
                right--;
            }else if(numbers[left] + numbers[right] < target){
                left++;
            }else{
                ret.push_back(left+1);
                ret.push_back(right+1);
                break;
            }
        }
        
        return ret;
    }
};

int main(){




    return 0;
}
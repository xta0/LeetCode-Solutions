#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {
    
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        numbers = nums;
        std::sort(numbers.begin(), numbers.end());
        vector<vector<int>> threes;
        for(int i=0;i<nums.size();++i){
            int x = numbers[i];
            auto twos = twoSum(i+1,-x);
            if(twos.size() > 0){
                for(auto arr : twos){
                    arr.push_back(x);
                    threes.push_back(arr);
                }
            }
        }
        return threes;
    }
private:
    vector<int> numbers;
    vector<vector<int>> twoSum(int begin, int target){
        vector<vector<int>> twos;
        int i=begin;
        int j = (int)numbers.size()-1;
        while(i<j){
            int l = numbers[i];
            int r = numbers[j];
            if(l+r < target){
                j--;
            }else if(l+r == target){
                vector<int> tmp;
                tmp.push_back(l);
                tmp.push_back(r);
                twos.push_back(tmp);
            }else{
                i++;
            }
        }
        return twos;
    }
};
int main(){
    
    Solution s;
    vector<int> input = {-1,0,1,2,-1,-4};
    s.threeSum(input);
    
    return 0;
}

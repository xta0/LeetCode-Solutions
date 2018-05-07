#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        if(nums.size() == 0){
            return {};
        }else{
            vector<vector<int>> ret ;
            //get the last element
            int back = nums.back();
            nums.pop_back();
            vector<vector<int>> last = subsets(nums);
            for(auto vec : last){
                vec.push_back(back);
                ret.push_back(vec);
            }
            return ret;
        }
    }
};
int main(){

    Solution s;
    vector<int> input = {1,2,3};
    vector<vector<int>>ret = s.subsets(input);
    for(auto vec: ret){
        cout<<"[";
        for(auto n : vec){
            cout<<n<<",";
        }
        cout<<"],"<<endl;
    }
    return 0;
}
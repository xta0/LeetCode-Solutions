#include <iostream>
#include <set>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        if(nums.size() == 0){
            return {};
        }else{
            set<vector<int>> ret ;
            //get the last element
            int back = nums.back();
            nums.pop_back();
            vector<vector<int>> last = subsetsWithDup(nums);
            for(auto vec : last){
                vec.push_back(back);
                ret.insert(vec);
            }
            return {ret.begin(),ret.end()};
        }
    }
};
int main(){
    Solution s;
    vector<int> v = {1,2,2};
    vector<vector<int>>ret = s.subsetsWithDup(v);
    for(auto vec: ret){
        cout<<"[";
        for(auto n : vec){
            cout<<n<<",";
        }
        cout<<"],"<<endl;
    }

    return 0;
}
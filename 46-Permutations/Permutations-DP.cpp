#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

//全排列, 动态规划
class Solution {
public:
    //[1] -> { [1] }
    //[1,2] -> { 1,[2] } -> { [1,2], [2,1] }
    //[1,2,3] -> {1,[2,3]} -> {1,{2,[3]} } -> {[1,[2,3]],[1,[3,2]]}->{[1,2,3],[2,1,3],[2,3,1],[1,3,2],[3,1,2],[3,2,1]}
    vector<vector<int>> permute(vector<int>& nums) {
        if(nums.size() == 1){
            return {nums};
        }else{
            vector<vector<int>> ret;
            int n = nums[0];
            auto remain(nums);
            remain.erase(find(remain.begin(), remain.end(), n));
            auto last_vectors = permute(remain);
            for(auto vec: last_vectors){
                for(int i=0;i<=vec.size();++i){
                    auto tmp (vec);
                    tmp.insert(tmp.begin()+i,n);
                    ret.push_back(tmp);
                }
            }
            return ret;
        }
    }
};

int main(){
    Solution s;
    vector<int> input({1,2,3});
    auto result = s.permute(input);
    for(auto vec: result){
        cout<<"[ ";
        for(auto n:vec){
            cout<<n<<" ";
        }
        cout<<"],"<<endl;
    }
    return 0;
}

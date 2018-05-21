#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;

//组合
class Solution {
public:
    //解法同#46
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        if(nums.size() == 1){
            return {nums};
        }else{
            set<vector<int>> ret;
            int n = nums[0];
            auto remain(nums);
            remain.erase(find(remain.begin(), remain.end(), n));
            auto last_vectors = permuteUnique(remain);
            for(auto vec: last_vectors){
                for(int i=0;i<=vec.size();++i){
                    auto tmp (vec);
                    tmp.insert(tmp.begin()+i,n);
                    ret.insert(tmp);
                }
            }
            return {ret.begin(), ret.end()};
        }
    }
};

int main(){
    Solution s;
    vector<int> input({1,1,2});
    auto result = s.permuteUnique(input);
    for(auto vec: result){
        cout<<"[ ";
        for(auto n:vec){
            cout<<n<<" ";
        }
        cout<<"],"<<endl;
    }
    return 0;
}

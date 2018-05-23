#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;

//组合, Divide and Conquer
//O(n^2)+O(n)
class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        if(nums.size() == 1){
            return {nums};
        }else{
            vector<vector<int>> ret;
            int n = nums.back();
            nums.pop_back();
            auto last_vectors = permuteUnique(nums);

            //剪枝
            if(last_vectors.size() == 1){
                if (n == last_vectors[0][0]){
                    return {{n,n}};
                }
            }
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
    vector<int> input({1,1,2,2});
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

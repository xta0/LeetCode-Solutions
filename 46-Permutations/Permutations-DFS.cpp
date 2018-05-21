#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

//全排列-深搜
class Solution {
private:

public:
    //[1] -> { [1] }
    //[1,2] -> { 1,[2] } -> { [1,2], [2,1] }
    //[1,2,3] -> {1,[2,3]} -> {1,{2,[3]} } -> {[1,[2,3]],[1,[3,2]]}->{[1,2,3],[2,1,3],[2,3,1],[1,3,2],[3,1,2],[3,2,1]}
    vector<vector<int>> permute(vector<int>& nums) {
        
    }
};

int main(){
    Solution s;
    vector<int> input({1,2,3,4});
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

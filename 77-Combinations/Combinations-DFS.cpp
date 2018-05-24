#include <iostream>
#include <vector>
#include <set>
using namespace std;

//组合-DFS
class Solution {
private:
    //index为每层数组循环的起始下标
    void dfs( int k, int index, vector<int>& nums, vector<int>& chosen, vector<vector<int>>& results){
        if(chosen.size() == k ){
            results.push_back(chosen);
        }else{
            for(int i = index; i<nums.size(); ++i){
                int n = nums[i];
                chosen.push_back(n);
                //观察决策树，下一层数组的起始index = 上一层index+1
                dfs(k,i+1, nums,chosen,results);
                chosen.pop_back();
            }
        }
    }
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> result;
        vector<int> nums;
        for(int i=1;i<=n;i++){
            nums.push_back(i);
        }
        vector<int> chosen;
        dfs(k,0,nums,chosen,result);
        return result;
    }
};

int main(){
    
    Solution s;
    auto result = s.combine(4,3);
    for(auto vec: result){
        cout<<"[ ";
        for(auto n:vec){
            cout<<n<<" ";
        }
        cout<<"],"<<endl;
    }

    return 0;
}

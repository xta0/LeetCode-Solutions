#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
  
        if(k > n){
            return {};
        }
        if(k == 1){
            vector<vector<int>> ret;
            for(int i=1; i<=n; i++){
                ret.push_back({i});
            }
            return ret;
        }
        if(k == n){
            vector<int> vec ;
            for(int i =1; i<=n; i++){
                vec.push_back(i);
            }
            return {vec};
        }
        
        //求前n-1的所有组合
        vector<vector<int>> last = combine(n-1,k);
        //累加前n-1个组合
        vector<vector<int>> ret(last);
        //求n-1,k-1
        vector<vector<int>> last2 = combine(n-1,k-1);
        for(auto vec : last2){
            vec.push_back(n);
            ret.push_back(vec);
        }
        return ret;
        
    }
};

int main(){
    Solution s;
    auto result = s.combine(5,3);
    for(auto vec: result){
        cout<<"[ ";
        for(auto n:vec){
            cout<<n<<" ";
        }
        cout<<"],"<<endl;
    }
    return 0;
}

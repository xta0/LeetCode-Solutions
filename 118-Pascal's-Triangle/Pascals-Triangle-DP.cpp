#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        if(numRows == 0){
            return {};
        }
        if(numRows == 1){
            return {{1}};
        }
        vector<vector<int>> ret;
        ret.push_back({1});
        ret.push_back({1,1});
        for(int i = 2; i<numRows; i++){
            vector<int> m = ret[i-1];
            vector<int> n (i+1,1);
            for(int j=0;j<m.size()-1;j++){
                n[j+1] = m[j]+m[j+1];
            }
            ret.push_back(n);
        }
        return ret;
    }
};

int main(){
    
    Solution s;
    auto x = s.generate(5);
    
    
    
    return 0;
}

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
private:
    int rBound(vector<int>& vec, int target){
        for(int i=0;i<vec.size();++i){
            if(vec[i]>=target){
                return i;
            }
        }
        return -1;
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ret;
        std::sort(candidates.begin(), candidates.end());
        int r = rBound(candidates,target);
        

        

        return ret;
    }
};

int main(){




    return 0;
}
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

class Solution {
private:
    int rBound(vector<int>& vec, int target){
        for(int i=0;i<vec.size();++i){
            if(vec[i]==target){
                return i;
            }else if(vec[i] > target){
                return i-1;
            }
        }
        return -1;
    }

public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ret;
        map<int,int> dict;//set a cache
        for(int i=0;i<candidates.size();++i){
            dict[candidates[i]] = i;
        }
        std::sort(candidates.begin(), candidates.end());
        int r = rBound(candidates,target);

        for(int i=0;i<=r; ++i){
            int 
        }
        


        

        return ret;
    }
};

int main(){




    return 0;
}
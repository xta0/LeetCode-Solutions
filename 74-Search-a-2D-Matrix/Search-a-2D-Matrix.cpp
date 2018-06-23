#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
      void helper(vector<vector<int>>& a,int target, pair<int,int>& pt, bool& found){
        if(pt.second < 0 || pt.first > a.size()-1){
            return;
        }
        //start from top-right
        if(target > a[pt.first][pt.second]){
            pt.first += 1;
        }else if(target < a[pt.first][pt.second]){
            pt.second -= 1;
        }else{
            found = true;
            return;
        }
        helper(a,target,pt,found);
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.size() == 0){
            return false;
        }
        if(matrix[0].empty()){
            return false;
        }
        bool found = false; pair<int,int> pt = make_pair<int,int>(0,(int)matrix[0].size()-1);
        helper(matrix,target,pt,found);
        return found;
    }
};

int main(){




    return 0;
}
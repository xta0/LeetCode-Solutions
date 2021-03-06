#include <iostream>
#include <vector>
#include <map>
using namespace std;

/*
 搜索矩阵：
 
 1. 从右上角开始记录坐标(x,y)
 2. 如果target比`a[x][y]`大，则向下(x,y-1)
 3. 如果target比`a[x][y]`小，则向左(x-1,y)
 
 递归上述过程
 */
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
    vector<vector<int>> matrix = {{1,4,7,11,15},{2,5,8,12, 19},{3,   6,  9, 16, 22},{10, 13, 14, 17, 24},{18, 21, 23, 26, 30}};
    Solution s;
    cout<<s.searchMatrix(matrix, 20)<<endl;
    return 0;
}

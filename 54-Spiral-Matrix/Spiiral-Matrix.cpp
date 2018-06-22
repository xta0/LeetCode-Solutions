#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
    void helper(vector<vector<int>>& a, int w, int h, int x, int y, vector<int>& result){
        if( w <=0 || h<= 0){
            return;
        }
        if(w == 1 && h == 1){
            result.push_back(a[x][y]);
            return;
        }
        for(int i=0;i<w;i++){
            result.push_back(a[x][y+i]);
        }
        for(int i=1;i<=h-2;i++){
            result.push_back(a[y+i][x+w-1]);
        }
        for(int i=w-1; i>=0; i--){
            result.push_back(a[y+h-1][x+i]);
        }
        for(int i=h-2; i>=1; i--){
            result.push_back(a[y+i][x]);
        }
        helper(a,w-2,h-2,x+1,y+1,result);
    }
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int h = (int)matrix.size();
        if(h == 0){
            return {};
        }
        int w = (int)matrix[0].size();
        if(w == 0){
            return {};
        }

        vector<int> result;
        helper(matrix,w,h,0,0,result);
        
        return result;
    }
};

int main(){
    Solution s;
    vector<vector<int>> matrix = {};
//    vector<vector<int>> matrix = {{1, 2, 3, 4},{5, 6, 7, 8},{9,10,11,12}};
    auto result = s.spiralOrder(matrix);
    for(auto x: result){
        cout<<x<<" ";
    }
    return 0;
}

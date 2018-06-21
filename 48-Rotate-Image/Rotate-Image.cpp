#include <iostream>
#include <vector>
#include <string>
using namespace std;

//核心思路是递归，找坐标对应关系
class Solution {
public:
    void helper(vector<vector<int>>& a, int x, int y, int n){
        if(n <= 1){
            return;
        }
        int sz = n-1;
        for(int i=0; i<sz; i++){
            int tmp = a[x][y+i];
            a[x][y+i] = a[x+sz-i][y];
            a[x+sz-i][y] = a[x+sz][x+sz-i];
            a[x+sz][x+sz-i] = a[x+i][y+sz];
            a[x+i][y+sz] = tmp;
        }
        helper(a,x+1,y+1, n-2);
    }
    void rotate(vector<vector<int>>& matrix) {
        helper(matrix,0,0,(int)matrix.size());
    }
};

int main(){
    vector<vector<int>> matrix = {{5,1,9,11},{2,4,8,10},{13,3,6,7},{15,14,12,16}};
    Solution s;
    s.rotate(matrix);
    for(auto v : matrix){
        for(auto x: v){
            cout<<x<<" ";
        }
        cout<<endl;
    }

    return 0;
}

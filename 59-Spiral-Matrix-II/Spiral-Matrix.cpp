#include <iostream>
#include <vector>
#include <string>
using namespace std;

//模板 #54
class Solution {
public:
    void helper(int& n, vector<vector<int>>& a, int x, int y, int& i){
        if( i > n ){
            return;
        }
        //top: left -> right
        for(int i=0;i<n;i++){
            a[x][y+i] = i;
            i++;
        }
        i--;
        //right: top->bottom
        for(int i=1;i<=n-2;i++){
            a[y+i][x+n-1]=i;
            i++;
        }
        i--;
        //bottom: right->left
        for(int i=n-1;i>=0; i--){
            a[y+n-1][x+i] = i;
            i++;
        }
        i--;
        //left: bottom -> top
        for(int i=n-2; i>=1; i--){
            a[y+i][x]=i;
        }
        i--;
        helper(n,a,x-1,y-1,i);
    }
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> matrix(n,vector<int>(n,0));
        int i = 1;
        helper(n,matrix,0,0,i);
        return matrix;
    }
};

int main(){

    Solution s;
    auto m = s.generateMatrix(4);
    for(auto v : m){
        for(auto x : v){
            cout<<x<<" ";
        }
        cout<<endl;
    }


    return 0;
}
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;


/*
DFS solution
Time Complexity: O(2^n) Timeout
Space Complexity: O(1)
*/
class Solution {


public:
    /*
    i,j: 当前位置
    w,h: 迷宫宽高
    result: 引用类型，保存返回结果
    */
    void dfs(int i, int j, int w, int h, int& result){
        if(i<0||i>=h || j<0||j>=w){
            return ;
        }
    
        if(i==h-1 && j==w-1){
            result ++;
            return;
        }
        
        dfs(i+1,j,w,h,result);
        dfs(i,j+1,w,h,result);
        
    }
    int uniquePaths(int m, int n) {
        int num = 0;
        dfs(0,0,m,n,num);
        return num;
    }
};

int main(){
    Solution s;
    cout<<s.uniquePaths(3,3)<<endl;    
    return 0;
}

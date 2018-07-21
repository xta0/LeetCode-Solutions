#include <iostream>
#include <vector>
#include <map>
using namespace std;

//DFS+backtracking, 解法超时
class Solution {
public:
    /*
     m: m列，x轴， 1<=pt.first<=m
     n: n行，y轴， 1<=pt.second<=n
     pt: 当前坐标
     target: 目的地
     num: 解的个数
     */
    void dfs(int m, int n, pair<int,int>& pt, pair<int,int>& target, int& num ){
        cout<<"("<<pt.first<<","<<pt.second<<")";
        if(pt.second > n || pt.first > m){
            cout<<"return"<<endl;
            return ;
        }
        if(pt.first == target.first && pt.second == target.second){
            cout<<"found"<<endl;
            num ++;
            return;
        }
        
        //向右前进
        pt.second += 1;
        dfs(m,n,pt,target,num);
        pt.second -= 1;
        
        //向下前进
        pt.first += 1;
        dfs(m,n,pt,target,num);
        pt.first -= 1;
        cout<<"("<<pt.first<<","<<pt.second<<") return"<<endl;;
    }
    
    int uniquePaths(int m, int n) {
        pair<int,int> pt = {1,1};
        pair<int,int> target = {m,n};
        int num = 0;
        dfs(m,n,pt,target,num);
        return num;
    }
};

int main(){
    Solution s;
    cout<<s.uniquePaths(3,3)<<endl;    
    return 0;
}

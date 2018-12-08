#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;


/*
DFS solution + Memoization
Time Complexity: O(2^n) 
Space Complexity: O(1)
*/
class Solution {
    struct pair_hash {
        template <class T1, class T2>
        std::size_t operator () (const std::pair<T1,T2> &p) const {
            auto h1 = std::hash<T1>{}(p.first);
            auto h2 = std::hash<T2>{}(p.second);

            // Mainly for demonstration purposes, i.e. works but is overly simple
            return h1 ^ h2;  
        }
    };

public:
    /*
    i,j: 当前位置
    w,h: 迷宫宽高
    result: 引用类型，保存返回结果
    */
    int dfs(int i, int j, int w, int h, unordered_map<pair<int,int>,int, pair_hash>& um){
        if(i<0||i>=h || j<0||j>=w){
            return 0;
        }
    
        if(i==h-1 && j==w-1){
            return 1;
        }
        if(um[{i,j}] > 0){
            return um[{i,j}];
        }
        int c1 = dfs(i+1,j,w,h,um);
        int c2 = dfs(i,j+1,w,h,um);
        um[{i,j}] = c1+c2;
        return um[{i,j}];
        
    }
    int uniquePaths(int m, int n) {
        
        unordered_map<pair<int,int>,int,pair_hash> um;
        return dfs(0,0,m,n,um);
        
    }
};

int main(){
    Solution s;
    cout<<s.uniquePaths(3,3)<<endl;    
    return 0;
}

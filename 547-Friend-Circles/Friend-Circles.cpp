#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <unordered_set>
#include <unordered_map>
using namespace std;

/*
Solution: Union Find
Time: O(N)
Space: O(N)
*/
class Solution {
public:
    int findCircleNum(vector<vector<int>>& M) {
        int n = M.size();
        if(!n){return 0;}
        vector<int> parents(n,0);
        for(int i=0;i<n;i++){
            parents[i] = i;
        }
        
        //开始每个人都是独立的集合
        int count = n;
        //find 
        auto findRoot = [&](int i){
            while(i != parents[i]){
                i = parents[i];
            }
            return i;
        };

        //union
        auto unionTwo = [&](int i, int j){
            int root1 = findRoot(i);
            int root2 = findRoot(j);
            if(root1 != root2){
                //union
                //mark root2 -> root1
                parents[root2] = root1;
                count--; //没合并一个集合，count-1
            }
        };   
        
        for(int i=0;i<n;i++){
            for(int j=i+1; j<n;j++){ // avoid recalculate M[i][j], M[j][i]
                if(M[i][j] == 1){
                    unionTwo(i,j);
                }
            }
        }
        return count;
    }
};


int main(){




    return 0;
}
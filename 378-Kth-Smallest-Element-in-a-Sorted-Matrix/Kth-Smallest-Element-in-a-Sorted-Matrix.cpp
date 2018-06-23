#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int m = matrix.size();
        priority_queue<int,vector<int>,std::greater<int>> pq;
        for(int i=0;i<m;i++){
            for(int j=0;j<m;j++){
                pq.push(matrix[i][j]);
            }
        }
        int ret = 0;
        for(int i=0;i<k;i++){
            ret = pq.top();
            pq.pop();
        }
        return ret;
    }
};

int main(){


    return 0;
}
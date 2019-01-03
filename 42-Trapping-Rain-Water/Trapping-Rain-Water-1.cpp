#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <unordered_set>
#include <unordered_map>
using namespace std;

void log(vector<int>& v){
    for(auto x: v){
        cout<<x<<" ";
    }
    cout<<endl;
}
/*
 Solution: Scan 3 times
 Time: O(N)
 Space: O(1)
 */
/*
 对任意一个位置，存水量的体积 = min(左边高点，右边最高点)
 */
class Solution {
    public:
    int trap(vector<int>& height) {
        if(height.empty()){
            return 0;
        }
        int sz = (int)height.size();
        vector<int> left(sz,0);
        vector<int> right(sz,0);
        
        for(int i=1; i<sz;i++){
            left[i] = height[i] > height[i-1] ? left[i-1]:max(height[i-1],left[i-1]);
        }
        log(left);
        
        for(int i=sz-2;i>=0;i--){
            right[i] = height[i] > height[i+1]? right[i+1]:max(height[i+1],left[i+1]);
        }
        log(right);
        int sum = 0;
        for(int i=0; i<sz;i++){
            int v = min(left[i],right[i]) -height[i];
            sum += (v < 0 ? 0 : v);
        }
        return sum;
    }
};

int main(){
    Solution s;
    vector<int> input = {0,1,0,2,1,0,1,3,2,1,2,1};
    cout<<s.trap(input)<<endl;
    
    
    
    
    return 0;
}

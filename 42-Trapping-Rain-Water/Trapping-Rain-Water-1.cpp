#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <unordered_set>
#include <unordered_map>
using namespace std;

/*
 Solution: Scan 3 times
 Time: O(N*3)
 Space: O(N)
 */
/*
 对任意一个位置，存水量的体积 = min(左边高点，右边最高点) - 自己的高度
 
 1. 从左向右扫一遍，计算每个位置向左边看的最高点，存到left[i]
 2. 从右向左扫一遍，计算每个位置向右边看的最高点，存到right[i]
 3. 使用上面公式计算，sum += min(left[i], right[i]) - height[i]
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
        
        //计算每个位置左边看去的最高点
        left[0] = height[0];
        for(int i=1; i<sz;i++){
            left[i] = max(left[i-1],height[i]);
        }
        
        
        //计算每个位置右边看去的最高点
        right[sz-1] = height[sz-1];
        for(int i=sz-2;i>=0;i--){
            right[i] = max(right[i+1],height[i]);
        }
        
        int sum = 0;
        for(int i=0; i<sz;i++){
            //计算每个位置的存水体积
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

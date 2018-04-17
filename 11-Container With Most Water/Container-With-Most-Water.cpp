#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


class Solution {
public:
    int maxArea(vector<int>& height) {
        
        //greedy
        int start = 0,end = (int)height.size()-1;
        int area = 0,result = 0;
        
        while(start != end){
            int h1 = height[start];
            int h2 = height[end];
            if(h1 <= h2){
                area = h1 * (end - start);
                start ++;
            }else{
                area = h2 * (end-start);
                end--;
            }
            if(area > result){
                result = area;
            }
        }
        return result;
    }
};


int main(){
    
    return 0;
}

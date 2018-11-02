#include <iostream>
#include <vector>
#include <string>
using namespace std;

//
/*
[2,0,2,1,1,0]
三挡板 ,i,j,k
[0,i) 区间 存放0， i指向最后一个0后第一个元素，初值为0
[i,j) 区间存放1，j是游标，指向最后一个1的下一个位置，初值为0
[j,k) 存放待分配元素，k指向第一个2的前一个元素，初值为len-1
[k,len）存放2
*/
class Solution {
public:
    void sortColors(vector<int>& nums) {
        if(nums.size() <= 1){
            return;
        }
        int i=0; int j=0; int k=nums.size()-1;
        while(j<k){
            if(nums[j] == '0'){
                swap(nums[j],nums[i]);
                i++;
                j++;
            }else if(nums[j] == '1'){
                j++;
            }else{
                swap(nums[j],nums[k]);
                k--;
            }
        }
    }
};


int main(){




    return 0;
}
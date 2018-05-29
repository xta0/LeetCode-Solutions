#include <iostream>
#include <vector>
#include <map>
using namespace std;

//O(n) + O(n)
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int pmin = 0;
        int pmax = 0;
        int vmin = INT_MAX;
        int vmax = INT_MIN;
        map<int,int> dict;
        int ret = 0;
        for(int i=0;i<nums.size();++i){
            int x = nums[i];
            dict[x] = i;
            if(x >0 && x<vmin ){
                vmin = x;
                pmin = i;
            }
            if(x>0 && x >vmax){
                pmax = i;
                vmax = x;
            }
        }
        cout<<"min:"<<vmin<<", index:"<<pmin<<endl;
        cout<<"max:"<<vmax<<", index:"<<pmax<<endl;
        if( vmin == vmax){
            if(vmin == 1){
                return 2;
            }else{
                return 1;
            }
        }
        if(vmin > 1){
            return 1;
        }
        //pmin = 0;
        bool flag = false;
        for(int i=vmin; i<=vmax;i++){
            if(dict.find(i) == dict.end()){
                ret = i;
                flag = true;
                cout<<i<<endl;
                break;
            }
        }
        if(!flag){
            return nums[pmax]+1;
        }else{
            return ret;
        }
    }
};
int main(){
    Solution s;
//    vector<int> v = {1,2,0};
    vector<int> v = {3,4,-1,1};
    //  vector<int> v = {7,8,9,11,12};
    cout<<s.firstMissingPositive(v)<<endl;
    
    
    
    
    return 0;
}

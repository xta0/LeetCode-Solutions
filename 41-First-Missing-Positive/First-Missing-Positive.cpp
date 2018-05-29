#include <iostream>
#include <vector>
#include <map>
using namespace std;

//O(n) + O(n)
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        
        //最小值
        int vmin = INT_MAX;
        int pmin = 0;

        //最大值
        int pmax = 0;
        int vmax = INT_MIN;

        //次小值
        int vmin2 = 0;
        int pmin2 = 0;
        
        for(int i=0;i<nums.size();++i){
            int x = nums[i];

            //fin min
            if(x >0 && x<vmin ){
                vmin2 = vmin;
                vmin = x;
                pmin = i;
            }else{
                //x > vmin
                //find min2
                if(x > 0 && x < vmin2){
                    vmin2 = x;
                    pmin2 = i;
                }
            }
            //find max
            if(x>0 && x >vmax){
                pmax = i;
                vmax = x;
            }
        }
        cout<<"min:"<<vmin<<", index:"<<pmin<<endl;
        cout<<"max"<<vmax<<", index"<<pmax<<endl;
        cout<<"min2:"<<vmin2<<", index:"<<pmin2<<endl;
 
        //enumerate all possiblities
        if(vmin > 1){
            return 1;
        }else{
            //vmin == 1
            if(vmin2 == vmin){
                return 2;
            }else if(vmin2 == vmin+1){
                if(vmax == vmin2+1){
                    return vmax+1;
                }else{
                    return vmin2+1;
                }
            }else{
                return vmin+1;
            }
        }
    }
};
int main(){
    Solution s;
    vector<int> v1 = {1,2,0}; //3
    vector<int> v2 = {3,4,-1,1}; //2
    vector<int> v3 = {7,8,9,11,12}; //1
    vector<int> v4 = {1,2,3}; //4
    vector<int> v5 = {4,1,2,3}; //4
    cout<<s.firstMissingPositive(v1)<<endl;
    cout<<s.firstMissingPositive(v2)<<endl;
    cout<<s.firstMissingPositive(v3)<<endl;
    cout<<s.firstMissingPositive(v4)<<endl;
    cout<<s.firstMissingPositive(v5)<<endl;
    
    
    
    
    return 0;
}

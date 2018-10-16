#include <iostream>
#include <vector>
#include <string>
using namespace std;

//O(N)
class Solution {
public:
  //binary search
    int bs(vector<int>& arr, int x){
        int l = 0, r = arr.size()-1;
        while(arr[l]<= arr[r]){
            int mid = (l+r)/2;
            if(arr[mid] == x){
                return mid;
            }else if(arr[mid] > x ){
                if(arr[mid-1] < x){
                    return mid;
                }else{
                    r = mid-1;
                }
            }else{
                if(arr[mid+1]>x){
                    return mid+1;
                }else{
                    l = mid+1;
                }
            }
        }
        return -1;
    }
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        if(arr.size() == 0 ){
            return {};
        }
        if(k == arr.size()){
            return arr;
        }
        int index = -1;
        for(int i=0;i<arr.size();i++){
            if(arr[i] >= x){
                index = i;
                break;
            }
        }
        if(index == -1){
            index = (int)arr.size()-1;
            //return last k elements
            return vector<int>(arr.begin()+arr.size()-k, arr.end());
        }
        if(index == 0){
            //return first k elements
            return vector<int>(arr.begin(),arr.begin()+k);
        }
        
        
        vector<int> ret;
        int left=0,right=0;
        
        if(arr[index] == x){
            ret.push_back(x);
            left = index-1;
            right = index+1;
        }else{
            left = index-1;
            right = index;
        }
        
        while( left >= 0 && right < arr.size()){
            if( abs(arr[left] - x) <= abs(arr[right]-x)){
                ret.push_back(arr[left]);
                left = left-1;
            }else{
                ret.push_back(arr[right]);
                right = right+1;
            }
            if(ret.size() == k){
                break;
            }
        }
        if(left < 0 && ret.size()<k){
            int sz = k-(int)ret.size();
            for(int i=0;i<sz;i++){
                ret.push_back(arr[right]);
                right ++;
            }
        }
        if(right >= arr.size() && ret.size()<k){
            int sz = k-(int)ret.size();
            for(int i=0; i<sz; i++){
                ret.push_back(arr[left]);
                left --;
            }
        }
        std::sort(ret.begin(),ret.end());
        return ret;
    }
};

int main(){
    
     Solution s;
    // vector<int> input = {1,2,3,4,5};
    
    // vector<int> ret = s.findClosestElements(input, 4, 3);
    // for(auto x :ret){
    //     cout<<x<<endl;
    // }

    //test search
    vector<int> v = {1,2,4,5,7};
    cout<<s.bs(v,6)<<endl;
    
    
    return 0;
}

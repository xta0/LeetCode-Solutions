#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    bool isMonotonic(vector<int>& A) {
        if(A.size()<=1){
            return true;
        }        
        int l = 0, r = 1;
        int delta = 0;
        while(r < A.size()){
            if(A[r] != A[l]){
                if(!delta){
                    delta = A[r]-A[l];
                }
                if(delta < 0){
                    if(A[r]-A[l] > delta){
                        return false;
                    }
                }else{
                    if(A[r]-A[l] < delta){
                        return false;
                    }
                }
            }
            l++;
            r++;
        }
        return true;
    }
};

int main(){

    vector<int> test = {5,4,3,1};
    Solution s;
    cout<<s.isMonotonic(test)<<endl;
    


    return 0;
}
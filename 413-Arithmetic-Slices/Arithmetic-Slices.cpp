#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int slices(int x){
        if(x == 3){
            return 1;
        }
        int y = slices(x-1);
        return y+(x-2);
    }
    int numberOfArithmeticSlices(vector<int>& A) {
        if(A.size() < 3){
            return 0;
        }
        int count = 2;
        int diff=A[1]-A[0];
        vector<int> results;
        for(int i=2;i<A.size();i++){
            if(A[i]-A[i-1] == diff){
                count++;
            }else{
                if(count>=3){
                    results.push_back(count);
                }
                diff=A[i]-A[i-1];
                count = 2;
            }
        }
        if(count>=3){
            results.push_back(count);
        }
  
        if(results.size()==0){
            return 0;
        }else{
            int sum =  0;
            for(auto x:results){
                sum += slices(x);
            }
            return sum;
        }
    }
};

int main(){
    Solution s;
    vector<int> A = {1,2,3,8,9,10};
    cout<<s.numberOfArithmeticSlices(A)<<endl;;

    return 0;
}

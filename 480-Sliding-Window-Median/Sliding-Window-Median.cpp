#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <unordered_set>
#include <unordered_map>
using namespace std;

//使用bst
class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        //bbst
        multiset<int> ms(nums.begin(),nums.begin()+k);
        //maintain a mid pointer
        multiset<int>::iterator midItor = next(ms.begin(),(k-1)/2);

        //move window
        
        
        
        
        
        }
};

int main(){

    multiset<int> ms{1,2,3};
    for(auto x: ms){
        cout<<x<<endl;
    }


    return 0;
}
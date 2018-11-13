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

class Solution {
    int bits(int n){
        int count = 0;
        while(n!=0){
            count++;
            n = n&(n-1);
        }
        return count;
    }
public:
    vector<int> countBits(int num) {
        vector<int> ans;
        for(int i=0;i<=num;i++){
            ans.push_back(bits(i));
        }
        return ans;
    }
};

int main(){




    return 0;
}
#include <iostream>
#include <vector>
#include <string>
using namespace std;

//Decrease and Conqure
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        if(numRows == 0){
            return {};
        }
        if(numRows == 1){
            return {{1}};
        }
        auto ret = generate(numRows - 1);
        auto last = ret.back();
        vector<int> n(numRows,1);
        for(int i =0; i<last.size()-1; i++){
            n[i+1] = last[i]+last[i+1];
        }
        ret.push_back(n);
        return ret;
    }
};

int main(){




    return 0;
}
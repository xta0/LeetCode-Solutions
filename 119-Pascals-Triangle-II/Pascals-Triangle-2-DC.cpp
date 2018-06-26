#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        if(rowIndex == 0){
            return {1};
        }
        //Decrease and Conqure
        auto last = getRow(rowIndex - 1);
        vector<int> n(rowIndex+1,1);
        for(int i =0; i<last.size()-1; i++){
            n[i+1] = last[i]+last[i+1];
        }
        return n;
    }
};

int main(){




    return 0;
}
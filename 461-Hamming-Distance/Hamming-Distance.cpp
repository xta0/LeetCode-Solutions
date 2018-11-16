#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int hammingDistance(int x, int y) {
        //get all 1s
        int z = x^y;
        int count = 0;
        //remove last 1 till z becomes 0
        while(z!=0){
            z = z&(z-1);
            count++;
        }
        return count;
    }
};

int main(){




    return 0;
}
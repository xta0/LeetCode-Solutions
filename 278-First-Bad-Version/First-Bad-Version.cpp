#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <unordered_map>
using namespace std;

// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {
public:
    //binary search
    int firstBadVersion(int n) {
        int lo = 1;
        int hi = n;
        while(lo <= hi){
            int mid = lo + (hi-lo)/2;
            if(isBadVersion(mid) == false){
                lo = mid+1;
            }else{
                if(mid == 1 || isBadVersion(mid-1) == false){
                    return mid;
                }else{
                    hi = mid-1;
                }
            }
        }
        return -1;
    }
};

int main(){




    return 0;
}
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

// Forward declaration of the knows API.
bool knows(int a, int b);

class Solution {
public:
    int findCelebrity(int n) {
        int x = 0;
        //第一遍扫描，判断celebrity可能的位置
        for(int i=1; i<n;i++){
            //如果x认识i，那么x一定不是celebrity,i可能是celebrity，令x=i
            //如果x不认识i，那么x可能是celebrity，i一定不是，令i++
            if(knows(x,i)){
                x = i;
            }
        }
        //虽然knows(x,i)=true可以表示x认识i，i可能是celebrity，但是并不能说i一定不认识x，i也可能认识x，这种情况下，i就不是celebrity
        //因此，第一遍扫描完后，我们还要做一遍double check
    
        for(int i=0;i<n;i++){
            if(i==x){
                continue;
            }
            if(!knows(i,x) || knows(x,i)){
                return -1;
            }
        }
        return x;
    
    }
};
int main(){




    return 0;
}
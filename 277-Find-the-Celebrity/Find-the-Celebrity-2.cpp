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
    int find(int start, int end){
        if(start == end){
            return start;
        }
        int x = find(start, end/2);
        int y = find(end/2 + 1, end);
        
        if(x==-1 && y==-1){
            return -1;
        }else if(x==-1 && y >= 0){
            return y;
        }else if(x>=0 && y == -1){
            return x;
        }else{
            if(knows(x,y)){
                if(!knows(y,x)){
                    return y;
                }else{
                    return -1;
                }
            }else{
                if(knows(y,x)){
                    return x;
                }else{
                    return -1;
                }
            }
        }        
    }
    int findCelebrity(int n) {
        return find(0,n-1);
    }
};
int main(){

    return 0;
}
#include <string>
#include <climits>
using namespace std;
class Solution {
public:
    int reverse(int x) {
        bool has_minus = x<0?true:false;
        std::string sx = std::to_string(abs(x));
        for(int i=0;i<sx.length()/2;++i){
            char tmp = sx[i];
            sx[i] = sx[sx.length()-1-i];
            sx[sx.length()-1-i] = tmp;
        }
        long result = std::stol(sx);
        if(result > INT_MAX){
            return 0;
        }else{
            return has_minus? -(int) result:(int)result;
        }
        
    }
};
int main(){
    return 0;
}

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int minAddToMakeValid(string S) {
        int ubl = 0;
        int ubr = 0;
        for(auto c:S){
            if(c=='('){
                ubl++;
            }else{
                if(ubl>0){
                    ubl--;
                }else{
                    ubr++;
                }
            }
        }
        return ubl+ubr;
    }
};

int main(){




    return 0;
}
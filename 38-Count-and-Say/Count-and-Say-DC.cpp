#include <iostream>
#include <string>
#include <vector>
using namespace std;

//分治
//Decrease & Conqure
class Solution {
public:
    string countAndSay(int n) {
        if(n == 1){
            return "1";
        }
        string str = countAndSay(n-1);
        int sz = str.length();
        int left = 0, right = 0, count = 0;
        char cl;
        string ret("");
        while( left< sz ){
            count = 0; cl = str[left];
            while(str[right] == cl){
                count ++;
                right ++;
                if(right >= sz){
                    break;
                }
            }
            ret += to_string(count) +  string(1,cl);
            left += count;
        }
        
        return ret;
    }
};

int main(){
    
    Solution s;
    cout<<s.countAndSay(5)<<endl;;
    
    
    return 0;
}

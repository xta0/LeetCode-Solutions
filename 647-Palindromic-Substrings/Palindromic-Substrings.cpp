#include <iostream>
#include <string>
#include <vector>
using namespace std;

/*
 中心扩散 O(n^2)
 */
class Solution {
private:
    size_t helper(string& ss, int left, int right){
        int count = 0;
        while( left > 0 && right < ss.length()-1){
            if(ss[left - 1] == ss[right + 1]){
                count ++;
                left --;
                right ++;
            }else{
                break;
            }
        }
        return count;
    }
public:
    int countSubstrings(string s) {
        int ret = 0;
        int k = 0;
        for(int i =0; i<s.length();++i){

        }

        return ret;
    }
};

int main(){
    Solution s;
    cout<<s.countSubstrings("aaaa")<<endl; //6
    
    return 0;
}

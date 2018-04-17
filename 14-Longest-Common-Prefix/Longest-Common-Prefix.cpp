#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        
        if(strs.size() == 0){
            return "";
        }
        string result("");
        for(int i=0;i<strs[0].length();++i){
            char target = strs[0][i];
            bool stop = false;
            for(int j=1; j<strs.size();++j){
                string str = strs[j];
                if(i < str.length()){
                    char c = str[i];
                    if(c != target){
                        stop = true;
                        break;
                    }
                }else{
                    stop = true;
                    break;
                }
            }
            if(!stop){
                result += string(1,target);
            }else{
                break;
            }
        }
        return result;
    }
};

int main(){
    
    Solution s;
    vector<string> test1{"flower","flow","flight"};
    vector<string> test2{"dog","racecar","car"};
    vector<string> test3{};
    cout<<s.longestCommonPrefix(test1)<<endl;
    cout<<s.longestCommonPrefix(test2)<<endl;
    cout<<s.longestCommonPrefix(test3)<<endl;
    
    
    return 0;
}

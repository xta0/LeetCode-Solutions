#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <unordered_map>
#include <unordered_set>
using namespace std;

//sliding window template
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        //check corner case
        if(s1.size() > s2.size()){
            return false;
        }

        //collect the count of each char in s1
        unordered_map<char,int> um;
        for(auto c:s1){
            um[c]++;
        }
        //start a sliding window
        int l=0; int r=0;
        int count = um.size();
        while( r<s2.size()){
            char c = s2[r];
            //check count
            if(um.count(c)){
                um[c]--;
                if(um[c]==0){
                    count--;
                    if(count == 0){
                        return true;
                    }
                }
            }
            r++;
            //move window
            if(r-l == s1.length()){
                
                char c = s2[l];
                //move 1 step
                if(um.count(c)>0){
                    um[c]++;
                    if(um[c]==1){
                        count++;
                    }
                }
                l++;
            }
            
        }
        return false; 
    }
};
int main(){
    Solution s;
    string s1 = "cat";
    string s2 = "xyccta";
    cout<<s.checkInclusion(s1, s2)<<endl;;
    return 0;
}
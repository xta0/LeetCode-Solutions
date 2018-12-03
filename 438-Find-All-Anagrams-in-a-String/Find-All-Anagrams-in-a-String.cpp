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

class Solution {
public:
    //sliding window
    vector<int> findAnagrams(string s, string p) {
        unordered_map<char,int> um;
        for(auto &c:p){
            um[c]++;
        }
        vector<int> res;
        //two pointers
        int left = 0;
        int right = 0;
        
        int counter = um.size();
        while(right < s.size()){
            char c = s[right];
            if(um.count(c)){
                um[c]--;
                if(um[c]==0){
                    counter--;
                }
            }
            while(counter == 0){
                if(right - left + 1 == p.size()){
                    res.push_back(left);
                }
                char c = s[left];
                if(um.count(c)){
                    um[c]++;
                    if(um[c] > 0){
                        counter++;
                    }
                }
                left ++;
            }
            right ++;
        }
        return res;
    }
};
int main(){

    Solution s;
    s.findAnagrams("cbaebabacd","abc");


    return 0;
}
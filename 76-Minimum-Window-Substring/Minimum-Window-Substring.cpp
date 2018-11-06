#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;

class Solution {
private:
    void updateLeftBoundary(string& s, int l, int r, int count){
        while(l < r-count){
            
        }
    }
public:
    string minWindow(string s, string t) {
        map<char,int> orig;
        for(auto c:t){
            orig[c] ++ ;
        }
        map<char,int> dict(orig);
        int count = t.size();
        int len = s.size();
        int l=0;int r=0;
        while( r < s.size() ){
            char c = s[r];
            if(dict.count(c) && count > 0){
                if(dict[c] > 0){
                    dict[c] --;
                    count --;
                    if(count == 0){

                    }
                }
            }
        }
        return s.substr(l,r-l);
    }
};

int main(){




    return 0;
}
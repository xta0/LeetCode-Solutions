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
        //统计模式串的词频
        map<char,int> dict;
        for(auto c:t){
            dict[c] ++ ;
        }
        int counter = dict.size();
        int left=0;int right=0;

        int len = INT_MAX;
        while(right < s.size()){
            char c= s[right];
            if(dict.count(c)){
                dict[c]--;
                if(dict[c] == 0){
                    counter --;
                }
            }
            right++;
            while(counter == 0){
                char c = s[left];
                if(dict.count(c)){
                    dict[c]++;
                }
            }

        }
    }
};

int main(){




    return 0;
}
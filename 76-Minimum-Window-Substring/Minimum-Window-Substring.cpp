#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        //统计模式串的词频
        map<char,int> dict;
        for(auto c:t){
            dict[c] ++ ;
        }
        int counter = 0;
        int left=0;int right=0;
        int index = 0;
        int len = INT_MAX;
        while(right < s.size()){
            char c= s[right];
            if(dict.count(c)){
                dict[c]--;
                if(dict[c] == 0){
                    counter ++;
                }
            }
            while(counter == dict.size()){
                if(right - left + 1 < len){
                    len = right-left+1;
                    index = left;
                }
                char c = s[left++];
                if(dict.count(c)){
                    dict[c]++;
                    if(dict[c] == 1){
                        counter  --;
                    }
                }
            }
            right ++;

        }
        return len==INT_MAX?"":s.substr(index);
    }
};

int main(){




    return 0;
}
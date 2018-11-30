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
        /*
        {
            x:1
            y:2
            z:1
        }
        counter = 3
        x: 0 --> counter = 3-1 = 2
        y: 1 --> counter = 2
        z: 0 --> counter = 2-1 = 1
        y: 0 --> counter = 1-1 = 0
        [123xyabcyssz]
        //update the length
        len = min(len, r-l+1)
        //move the left boundary
        [123xyabcyssz]
            |
         {
            x:1 --> counter = 1
            y:0
            z:0
        }
        //keep expending the right boundary
        [123xyabcyssz]
             |      |
        */
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
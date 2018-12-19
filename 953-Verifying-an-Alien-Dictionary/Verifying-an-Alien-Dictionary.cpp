#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
    bool compareTwoWords(string& w1, string& w2, vector<int>& buckets){
        int index = 0;
        while(index < w1.size() && index < w2.size()){
            char c1 = w1[index];
            char c2 = w2[index];
            if(c1 != c2){
                return  buckets[c1-'a'] < buckets[c2-'a'];
            }
            index++;
        }
        return index>=w1.size();
    }
public:
    bool isAlienSorted(vector<string>& words, string order) {
        if(words.size() <= 1){
            return true;
        }
        int sz = order.size();
        vector<int> buckets(sz,-1);
        for(int i=0;i<order.size();i++){
            char c = order[i];
            buckets[c-'a'] = i;
        }
        
        for(int i=0;i<words.size();i++){
            if(i+1 < words.size()){
                if(!compareTwoWords(words[i],words[i+1],buckets)){
                    return false;
                }
            }
        }
        
        return true;
    }
};

int main(){




    return 0;
}
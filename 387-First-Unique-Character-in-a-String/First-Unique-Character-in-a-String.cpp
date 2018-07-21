#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char,int> hash_table;
        vector<int> array(26,0);
        for(auto c : s){
            array[c-'a'] ++;
        }
        for(int i=0;i<s.length();i++){
            char c = s[i];
            if(array[c-'a'] == 1){
                return i;
            }
        }
        return -1;
    }
};

int main(){




    return 0;
}
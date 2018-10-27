#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size()){
            return false;
        }
        if(!s.size() && !s.size()){
            return true;
        }
        unordered_map<char,int> _map;
        for(auto c :s){
            _map[c] +=1;
        }
        for(auto c:t){
            if(_map.find(c) != _map.end() && _map[c] >= 1){
                _map[c] -= 1;
            }else{
                return false;
            }
        }
        return true;
    }
};

int main(){




    return 0;
}
#include <iostream>
#include <vector>
#include <map>
using namespace std;

//1. 排序
//2. 使用map
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> results;
        map<string, vector<string>> cache;
        for(auto str:strs){
            string tmp = str;
            sort(tmp.begin(),tmp.end());
            if(cache.find(tmp) == cache.end()){
                cache[tmp] = {};
            }
            cache[tmp].push_back(str);
        }
        for(auto pair : cache){
            results.push_back(pair.second);
        }
        return results;
    }
};

int main(){




    return 0;
}
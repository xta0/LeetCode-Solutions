#include <iostream>
#include <vector>
#include <map>
#include <queue>
using namespace std;

class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        if(words.empty()){
            return {};
        }
        
        vector<string> ret;
        map<string,int> m;
        //O(n)
        for(auto word:words){
            ++m[word];
        }
        //O(n)
        auto comp = [](const pair<string,int>&p1,const pair<string,int>&p2){
            if(p1.second < p2.second){
                return true;
            }else if(p1.second == p2.second){
                return p1.first > p2.first;
            }else{
                return false;
            }
        };
        priority_queue<pair<string,int>, vector<pair<string,int>>, decltype(comp)> pq{m.begin(),m.end(),comp};
        //O(n)
        for(int i=0;i<k;i++){
            string word = pq.top().first;
            pq.pop();
            ret.push_back(word);
        }
        return ret;
    }
};

int main(){    
    return 0;
}

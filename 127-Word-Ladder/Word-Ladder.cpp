#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <unordered_set>
#include <unordered_map>
using namespace std;

//BFS
class Solution {
public:
    vector<string> guess(const string& word, int index, unordered_set<string>& selected, unordered_set<string>& dict){
        vector<string> ans;
        for(int i=0;i<26;i++){
            char c = 'a'+i;
            if(c != word[index]){
                string tmp  = word;
                tmp[index] = c;
                if(!selected.count(tmp) && dict.count(tmp)){
                    ans.push_back(tmp);
                }
            }
        }
        return ans;
    }
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> us = {wordList.begin(), wordList.end()};
        unordered_set<string> selected;
        if(us.count(endWord) == 0){
            return 0;
        }
        queue<string> q;
        q.push(beginWord);
        selected.insert(beginWord);
        int level = 0;
        while(!q.empty()){
            level++;
            //遍历每一层
            size_t sz = q.size();
            for(int i=0;i <sz; i++){
                string word = q.front();
//                cout<<"visisted: "<<word<<endl;
                q.pop();
                for(int i = 0; i<word.size(); i++){
                    vector<string> possibleWords = guess(word,i,selected,us);
                    for(auto &pword: possibleWords){
                        if(pword == endWord){
                            return level+1;
                        }
                        if(!selected.count(pword)){
                            q.push(pword);
                            selected.insert(pword);
                        }
                    }
                }
            }
//            cout<<"---"<<endl;
        }
        return 0;
    }
};


int main(){
    Solution s;
    string begin = "hit";
    string end = "cog";
    vector<string> dict = {"hot","dot","dog","lot","log","cog"};
    s.ladderLength(begin,end,dict);
    
    
    
    
    return 0;
}

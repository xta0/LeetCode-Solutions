#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>

using namespace std;
typedef unordered_map<string, int> DICT;
class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        if(s.length() == 0 || words.size() == 0){
            return {};
        }
        int len = words[0].length();
        if(len > s.length()){
            return {};
        }
        vector<int> ret;
        int count = words.size();
        DICT d1;
        for(auto w : words){
            d1[w] ++ ;
        }
        
        for(int i=0;i<=s.length()-len*count+1;++i){
            DICT d2; int j = 0;
            for(; j<count; ++j){
                string str = s.substr(i+j*len,len);
                if(d1.find(str) != d1.end()){
                    d2[str]++;
                }else{
                    break;
                }
                if(d2[str] > d1[str]){
                    break;
                }
            }
            if(j == count){
                ret.push_back(i);
            }
            
        }

        return ret;
    }
};
int main(){

    Solution s;
//    vector<string> words = {"word","student"};
//    auto r = s.findSubstring("wordgoodstudentgoodword", words);
    
//    vector<string> words = {"fooo","barr","wing","ding","wing"};
//    auto r = s.findSubstring("lingmindraboofooowingdingbarrwingmonkeypoundcake", words);

//    vector<string> words = {"word","good","best","good"};
//    auto r = s.findSubstring("wordgoodgoodgoodbestword", words);

    // vector<string> words = {"foo","bar"};
    // auto r = s.findSubstring("barfoothefoobarman", words);

    vector<string> words = {"a"};
    auto r = s.findSubstring("a", words);
    
    for (auto n:r) {
        cout<<n<<" ";
    }
    


    return 0;
}
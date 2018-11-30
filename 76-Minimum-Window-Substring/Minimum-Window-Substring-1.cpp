#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int> um;
        for(auto &c:t){
            um[c]++;
        }
        unordered_map<char,int> tmp = um;
        int count = um.size();
        int len = INT_MAX;
        int index = 0; 
        for(int i=0;i<s.size();i++){
            for(int j=i;j<s.size();j++){
                char c = s[j];
                if(tmp.count(c)){
                    tmp[c] -- ;
                    if(tmp[c] == 0){
                        count --;
                        if(count == 0){
                            int curlen = j-i+1;
                            cout<<"len:"<<curlen<<endl;
                            cout<<"sustr:"<<s.substr(i,curlen)<<endl;
                            len = min(len,j-i+1);
                            index = i;
                            break;
                        }
                    }
                }
            }
            tmp = um;
            count = um.size();
            cout<<"--"<<endl;
        }
        
        return len==INT_MAX?"":s.substr(index,len);
    }
};

int main(){
    Solution s;
    cout<<s.minWindow("xyyzyzyx","xyz")<<endl;
    return 0;
}
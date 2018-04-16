#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> mymap(255,-1);
        int len = 0,i = -1,tmp;
        for(int j=0;j < s.length();j++)
        {
            tmp = mymap[s.at(j)];
            i = std::max(tmp,i);
            mymap[s.at(j)] = j;
            len = std::max(len,(j-i));
        }
        return len;
    }
};
int main(){
    Solution s;
    cout<<s.lengthOfLongestSubstring("abcaecbb")<<endl;

    return 0;
}
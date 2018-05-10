#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct TreeNode{
    string val;
    vector<TreeNode* > children;
};
class Solution {
private:
    // TreeNode* 

public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> ret;
        vector<string> comvec;
        for(auto str: words){
            vector<string> tmp(words);
            tmp.erase(str);
        
            // vector<string> words = 
            
        }


        return ret;
    }
};

int main(){




    return 0;
}
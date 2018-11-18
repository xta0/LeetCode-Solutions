#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <unordered_set>
#include <unordered_map>
using namespace std;

#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <numeric>
#include <map>
using namespace std;

class Solution {
    string repeat(int t, string s){
        string tmp = s;
        for(int i=0;i<t-1;i++){
            tmp +=s;
        }
        return tmp;
    }
public:
    string decodeString(string s) {

        //store numbers
        stack<int> stk1;
        //store strings
        stack<pair<int,string>> stk2;
        
        int level = 0;
        for(int i=0;i<s.size();i++){
            char c = s[i];
            if(isdigit(c)){
                //get the whole number
                string tmp = string(1,c);
                while(i+1<s.size() && isdigit(s[i+1])){
                    tmp += s[i+1];
                    i++;
                }
                stk1.push(stoi(tmp));
            }else if(c=='['){
                //increment the parenthesis
                level++;
            }else if(isalpha(c)){
                stk2.push({level,string(1,c)});
            }else if(c==']'){
                int times = 0;
                if(!stk1.empty()){
                    times = stk1.top();
                    stk1.pop();
                }
                string tmp="";
                //collect the string that has the same parenthesis level
                while(!stk2.empty() && stk2.top().first == level){
                    auto p = stk2.top();
                    stk2.pop();
                    tmp =  p.second + tmp;
                }
                tmp = repeat(times,tmp);
                level-=1;
                stk2.push({level,tmp});
            }
        }
        string ans = "";
        //collect the result
        while(!stk2.empty()){
            auto p = stk2.top();
            stk2.pop();
            ans = p.second + ans;
        }
        return ans;
        
    }
};
int main(){
    
    Solution s;
    string s1 = "3[a]2[bc]";
    string s2 = "3[a2[c]]";
    string s3 = "2[abc]3[cd]ef";
    string s4 = "10[Leetcode]";
    cout<<s.decodeString(s1)<<endl;
    cout<<s.decodeString(s2)<<endl;
    cout<<s.decodeString(s3)<<endl;
    cout<<s.decodeString(s4)<<endl;

    return 0;
}


int main(){




    return 0;
}
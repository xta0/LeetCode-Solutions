#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <unordered_set>
#include <unordered_map>
using namespace std;

/*
 1. check wether a input string is valid
 2. compute min number of unbalanced '(' and ')'
 3. Try all possible way to remove
 */
class Solution {
public:
    pair<int,int> scan(const string& s){
        int cl=0; int cr=0;
        for(auto c: s){
            if(c == '('){
                cl++;
            }else if(c==')'){
                if(cl > 0){
                    cl--;
                }else{
                    cr++;
                }
            }
        }
        return {cl,cr};
    }
    bool isValid(const string& s){
        
        auto p = scan(s);
        return p.first == 0 && p.second == 0;
    }
    
    //dfs 暴力搜索
    //1. 先移除右括号 + 回溯
    //2. 再移除左括号 + 回溯
    //3. 如果cr & cl 都为 0， check isvalid
    void dfs(string s, int index, int cl, int cr,unordered_set<string>& result){
        if(cl==0 && cr == 0){
            // cout<<"possible: "<<s<<endl;
            if(isValid(s)){
                result.insert(s);
            }
            return;
        }
        
        for(int i=index;i<s.size();i++){
            char c = s[i];
            //剪枝，无论左括号还是右括号，删除第一个即可
            if ( c == '(' || c==')'){
                if(i-1>=0 && s[i-1] == c){
                    continue;
                }
                if(c == ')' && cr > 0){
                    s.erase(i,1);
                    cr-=1;
                    dfs(s,i,cl,cr,result);
                    cr+=1;
                    s.insert(s.begin()+i,c);
                }
                if(c == '(' && cl > 0){
                    s.erase(i,1);
                    cl-=1;
                    dfs(s,i,cl,cr,result);
                    cl+=1;
                    s.insert(s.begin()+i,c);
                }
            }
            
        }
    }
    vector<string> removeInvalidParentheses(string s) {
        
        auto p = scan(s);
        if(p.first == 0 && p.second==0){
            return {s};
        }
        //括号去重
        unordered_set<string> result;
        dfs(s,0,p.first,p.second,result);
        if(result.empty()){
            return {""};
        }else{
            return {result.begin(), result.end()};
        }
    }
    
};

int main(){
    
    Solution s;
    string s1 = "()())()";
    string s2 = ")(";
    string s3 = "(a)())()";
    string s4 = "(()";
    string s5 = ")())(";
    string s6 = ")()(";
    auto v = s.removeInvalidParentheses(s6);
    for(auto str : v){
        cout<<str<<endl;
    }
    
    return 0;
}

#include <iostream>
#include <string>
#include <vector>
using namespace std;

/*
 遍历O(n^2)
 */
class Solution {
private:
    size_t count_palindromic_tring(string& ss, int pos, size_t radius){
        int count = 0;
        int rr = ss[pos]=='|'?1:0;
        while (rr <= radius) {
            int l = (int)(pos - rr);
            if(l < 0){
                break;
            }
            int r=  (int)(pos + rr);
            if(r > ss.length()){
                break;
            }
            char lc = ss[l];
            char rc = ss[r];
             if(lc==rc){
                if( lc != '|' && rc != '|'){
                    count++;
                }
            }else{
                break;
            }
            rr+=2;
        }
        return count;
    }
public:
    int countSubstrings(string s) {
        int ret = 0;
        //预处理
        string ss = s;
        for(int i=0;i<=s.length();++i){
            ss.insert(2*i, "|");
        }
        cout<<ss<<endl;
        vector<string> pl;
        for(int i =0; i<ss.length(); ++i){
            cout<<"pos: "<<ss[i]<<endl;
            size_t r = i > ss.length()/2 ? ss.length()-i : i;
            size_t count = count_palindromic_tring(ss,i,r);
            cout<<"count: "<<count<<endl;
            ret += count;
            cout<<"total: "<<ret<<endl;
            cout<<"-----------"<<endl;
        }
        return ret;
    }
};

int main(){
    Solution s;
    s.countSubstrings("aaa");
    
    return 0;
}

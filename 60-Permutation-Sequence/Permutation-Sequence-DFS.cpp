#include <iostream>
#include <vector>
#include <string>
using namespace std;

//DFS模板同 #46
class Solution {
public:
    void dfs(vector<int>& seq, vector<int>& chosen, int& num, int& k){
        if(seq.size() == 0){
            num++;
            return;
        }
        for(int i=0;i<seq.size();++i){
            int x = seq[i];
            //choose
            chosen.push_back(x);
            //delete choosen element
            seq.erase(seq.begin()+i);
            //dfs
            dfs(seq,chosen,num,k);
            //check k
            if(num == k){
                return;
            }else{   
                //backtrakcing
                //unchoose
                chosen.pop_back();
                //insert deleted element
                seq.insert(seq.begin()+i,x);
            }     
        }
        
    }
    string getPermutation(int n, int k) {
        vector<int> seq;
        for(int i=1;i<=n;i++){
            seq.push_back(i);
        }
        vector<int> kth; int num=0;
        dfs(seq,kth,num,k);
        string ret("");
        for(auto x:kth){
            ret += to_string(x);
        }
        return ret;
    }
};

int main(){




    return 0;
}
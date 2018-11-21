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

//拓扑排序
//BFS
//图 ——> 入度为0 -->BFS
class Solution {
public:
    string alienOrder(vector<string>& words) {
        if(words.size() == 0 ){
            return "";
        }
        //定义图
        unordered_map<char, unordered_set<char>> graph;
        //保存出度为0的节点
        unordered_map<char,int> degrees;
        //构造图 + 计算节点入度
        constructGraph(words, graph, degrees);
        //BFS拓扑排序
        queue<char> q;
        //度为0的节点入队
        for(auto& p:degrees){
            if(p.second == 0){
                q.push(p.first);
            }
        }
        string ans = "";
        while(!q.empty()){
            char c = q.front();
            q.pop();
            ans+=c;
            auto children = graph[c];
            for(auto child : children){
                degrees[child] --;
                if(degrees[child] == 0){
                    q.push(child);
                }
            }
        }
        //判断是否有环
        for(auto& p:degrees){
            //有换返回空
            if(p.second != 0){
                ans="";
                break;
            }
        }
        
        return ans;
        
    }
private:
    void constructGraph(vector<string>& words, unordered_map<char,unordered_set<char>>& graph, unordered_map<char, int>& degrees){
        
        for(int i=0;i<words.size();i++){
            
            //每个词和下一个词比较
            string word = words[i];
            string next = "";
        
            if(i+1<words.size()){
                next = words[i+1];
            }
            for(int j=0;j<word.size();j++){
                char c = word[j];
                //初始化每个字符的入度为0
                if(!degrees.count(c)){
                    degrees[c] = 0;
                }
                if(j < next.size()){
                    //word[0,j) == next[0,j) && word[j] != next[j] 字典序条件
                    if(c!=next[j] && word.substr(0,j) ==  next.substr(0,j)){
                        //避免重复记录入度
                        if(!graph[c].count(next[j])){
                            graph[c].insert(next[j]);
                            //更新入度
                            degrees[next[j]] ++;
                        }
                    }
                }
            }
        }
    }
};
int main(){
    
    Solution s;
//    vector<string> words = {"wrt","wrf","er","ett","rftt"};
//    vector<string> words = {"zy","zx"};
//    vector<string> words = {"z","x","y","x"};
    vector<string> words = {"za","zb","ca","cb"};
    cout<<s.alienOrder(words)<<endl;
    
    
    return 0;
}

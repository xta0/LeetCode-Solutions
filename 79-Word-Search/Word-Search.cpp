#include <iostream>
#include <vector>
#include <string>
#include <queue>
using namespace std;

//BFS
struct PT{
    int i;
    int j;
    char c;
    vector<PT> getChildren(vector<vector<char>>& board, int w, int h){
        vector<PT> ans;
        if(i-1>=0){
            ans.push_back({i,j,board[i-1][j]});
        }
        if(j-1>=0){
            ans.push_back({i,j,board[i][j-1]});
        }
        if(i+1<w){
            ans.push_back({i,j,board[i+1][j]});
        }
        if(j+1<h){
            ans.push_back({i,j,board[i][j+1]});
        }
        return ans;
    }
};
class Solution {
 
public:
    bool exist(vector<vector<char>>& board, string word) {
        int h = board.size();
        if(h==0) return false;
        int w = board[0].size();
        if(w==0) return false;
        vector<vector<bool>> marks(h,vector<bool>(w,false));
        for(int i=0; i<h; i++){
            for(int j=0;j<w;j++){
                if(board[i][j] == word[0]){
                    PT root = {i,j,word[0]};
                    queue<PT> q;
                    q.push(root);
                    int index = 1;
                    while(!q.empty()){
                        PT pt = q.front();
                        marks[pt.i][pt.j] = true;
                        cout<<"visit: "<<pt.c<<" ";
                        q.pop();
                        vector<PT> children = pt.getChildren(board,w,h);
                        for(auto& pt : children){
                            if(pt.c == word[index] && marks[pt.i][pt.j] == false){
                                q.push(pt);
                                cout<<"find: "<<pt.c<<"at: {"<<pt.i<<","<<pt.j<<"}"<<endl;
                                index++;
                            }
                        }
                    }
                    if(index == word.size()-1){
                        return true;
                    }
                }
            }
        }
        return false;
    }
};

int main(){
    Solution s;
    vector<vector<char>> matrix = {{'A','B','C','E'},{'S','F','C','S'},{'A','D','E','E'}};
    cout<<s.exist(matrix,"ABCCED")<<endl;;



    return 0;
}
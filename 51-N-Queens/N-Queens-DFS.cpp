#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <numeric>

//DFS+backtracking
using namespace std;
struct PT{

    int r;
    int c;
    bool operator<(const PT& other)const{
        if(r < other.r){
            return true;
        }else if(r == other.r){
            return c < other.c;
        }else{
            return false;
        }
    }
};

class Solution {
private:
    void log(vector<vector<bool>>& board){
        for(auto row : board){
            for(auto v: row){
                if(v == true){
                    cout<<"x";
                }else{
                    cout<<".";
                }
            }
            cout<<endl;
        }
        cout<<"------"<<endl;
    }
    void log2(vector<vector<bool>>& board, PT pt){
        int n = board[0].size();
        for(int i=0; i<n; ++i){
            for(int j=0;j<n;++j){
                if( i== pt.r && j==pt.c ){
                    cout<<"Q";
                }else{
                    cout<<".";
                }
            }
            cout<<endl;
        }
        cout<<"------"<<endl;
    }
    bool canBePlaced(int row, int col,vector<vector<bool>>& board){
        if(!board[row][col]){
            return true;
        }
        return false;
    }
    void place(int r, int c,vector<set<PT >>& states, vector<vector<bool>>& board){
        int n = (int)board.size();
        set<PT > tmp;
        //place the point
        tmp.insert({r,c});
        board[r][c]=true;
        
        //update other lines
        for (int i=1; i<n; i++) {
            //行
            if(!board[r][i]){
                PT pt = {r,i};
                tmp.insert(pt);
                board[r][i] = true;
            }
            //列
            if(!board[i][c]){
                tmp.insert({i,c});
                board[i][c] = true;
            }
            //对角线
            //左上
            if(r-i >=0 && c-i >=0 && !board[r-i][c-i]){
                tmp.insert({r-i,c-i});
                board[r-i][c-i] = true;
            }
            //右上
            if(r+i <n && c-i >=0 && !board[r+i][c-i]){
                tmp.insert({r+i,c-i});
                board[r+i][c-i] = true;
            }
            //右下
            if(r-i >=0 && c+i< n && !board[r-i][c+i]){
                tmp.insert({r-i,c+i});
                board[r-i][c+i] = true;
            }
            //左下
            if(r+i <n && c+i< n && !board[r+i][c+i]){
                tmp.insert({r+i,c+i});
                board[r+i][c+i] = true;
            }
        }
        states.push_back(tmp);
    }
    void unplace(int r, int c, vector<set<PT >>& states, vector<vector<bool>>& board){
        set<PT > pts = states.back();
        for(auto pt:pts){
            board[pt.r][pt.c] = false;
        }
        states.pop_back();
    }
    
    void dfs(int col,int n, vector<PT>& chosen, vector<vector<PT>>& results, vector<set<PT >>& states, vector<vector<bool>>& board){
        if(col >= n){
            results.push_back(chosen);
            return;
        }
        for(int row=0;row<n;++row){

            if(canBePlaced(row, col, board)){
                place(row, col, states, board);
                chosen.push_back({row,col});
                dfs(col+1, n, chosen, results,states, board);
                chosen.pop_back();
                unplace(row, col, states, board);
            }

        }
    }
    
public:
    vector<vector<string>> solveNQueens(int n) {
        
        vector<vector<bool>> board(n,vector<bool>(n,false));
        vector<set<PT >> states;
        vector<PT> chosen;
        vector<vector<PT>> results;
        dfs(0,n,chosen,results,states,board);
        
        //parse the result
        vector<vector<string>> ret;
        for(auto chosen : results){
            vector<string> tmp(n,string(n,'.'));
            for(auto pt: chosen){
                tmp[pt.r][pt.c] = 'Q';
            }
            ret.push_back(tmp);
        }
        for(auto v:ret){
            for(auto s:v){
                cout<<s<<","<<endl;
            }
            cout<<endl;
        }
        return ret;
    };
};

int main(){
    Solution s;
    s.solveNQueens(4);
    return 0;
}

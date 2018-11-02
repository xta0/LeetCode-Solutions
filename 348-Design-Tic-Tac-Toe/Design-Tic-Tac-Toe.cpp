#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <list>
using namespace std;


class TicTacToe {
    vector<vector<char>> board;
    int sz;
    int remain = 0;
public:
    /** Initialize your data structure here. */
    TicTacToe(int n) {
        board = vector<vector<char>>(n,vector<char>(n,' '));
        sz = n;
        remain = n*n;
    }
    
    int move(int row, int col, int player) {
        //(row,col) has been taken
        if(board[row][col] != ' ' ){
            return 0;
        }
        //board is full
        if(remain == 0){
            return 0;
        }
        char c = player == 1 ? 'x':'o';
        //place the item
        board[row][col] = c;
        
        if(horizontal(row, c) ||
           vertical(col, c) ||
           diognal_l2r(c) ||
           diognal_r2l(c)){
            return player;
        }
        remain--;
        return 0;
    }
    void print(){
        for(auto vec: board){
            for(auto c : vec){
                cout <<c<<" ";
            }
            cout<<endl;
        }
    }
private:
    //
    bool horizontal(int i,  char c){
        vector<char> v = board[i];
        for(auto &x:v){
            if(x!=c){
                return false;
            }
        }
        return true ;
    }
    bool vertical(int j, char c){
        for(auto vec : board){
            if(vec[j] != c){
                return false;
            }
        }
        return true;
    }
    bool diognal_r2l(char c){
        for(int i=0; i<sz; i++){
            if(board[i][i] != c){
                return false;
            }
        }
        return true;
    }
    bool diognal_l2r(char c){
        for(int i =0; i<sz; i++){
            if(board[i][sz-i-1] != c){
                return false;
            }
        }
        return true;
    }
};
int main(){

    /*
     ["TicTacToe","move","move","move","move","move","move","move"]
     [[3],[0,0,1],[0,2,2],[2,2,1],[1,1,2],[2,0,1],[1,0,2],[2,1,1]]
     */
    TicTacToe game(3);
    cout<<game.move(0, 0, 1)<<endl;;
    game.print();
    cout<<game.move(0,2,2)<<endl;
    game.print();
    cout<<game.move(2,2,1)<<endl;
    game.print();
    cout<<game.move(1,1,2)<<endl;
    game.print();
    cout<<game.move(2,0,1)<<endl;
    game.print();
    cout<<game.move(1,0,2)<<endl;
    game.print();
    cout<<game.move(2,1,1)<<endl;
    game.print();
    
}

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    void solveSudoku(vector<vector<char>> &board){
        for (int i = 0; i < board.size(); ++i){
            for (int j = 0; j < board.size(); ++j){
                char c = board[i][j];
                int num = c-'0';
                if(c == '.'){
                    blanks.push_back({i,j});
                }else{
                    set_state(i,j,num,1);
                }
            }
        }
        
        //from bottom to top
        //this->dfs(blanks.size()-1);
        //from top to bottom
        if(this->dfs(0,board)){
            //succeed
            for (int i = 0; i < board.size(); ++i){
                for (int j = 0; j < board.size(); ++j){
                    cout<<board[i][j]<<" ";
                }
                cout<<endl;
            }
        }else{
            //no solution
        }
    }
private:
    struct Value{
        int row;
        int col;
    };
    int col[9][10] = {0};
    int row[9][10] = {0};
    int block[9][10] = {0};
    vector<Value>blanks;
    
    bool dfs(int index, vector<vector<char>> &board){
        if(index >= blanks.size()){
            return true;
        }
        int row = blanks[index].row;
        int col = blanks[index].col;
        //enumerate
        for(int num = 1; num<=9; ++num ){
            if ( is_valid(row, col, num) ){
                board[row][col] = '0'+ num;
                set_state(row,col,num,1);
                if(this->dfs(index+1,board)){
                    return true;
                }else{
                    set_state(row,col,num,0);
                }
            }
        }
        
        return false;
    };
    bool is_valid(int r, int c, int num){
        if (!row[r][num] &&
            !col[c][num] &&
            !block[block_index(r, c)][num]){
            return true;
        }
        return false;
    }
    void set_state(int r, int c, int num, int value){
        col[c][num] = value;
        row[r][num] = value;
        block[block_index(r, c)][num] = value;
    }
    int block_index(int row, int col){
        return row / 3 * 3 + col / 3;
    }
};

int main(){
    vector<vector<char>> board{
        {'.','.','9','7','4','8','.','.','.'},
        {'7','.','.','.','.','.','.','.','.'},
        {'.','2','.','1','.','9','.','.','.'},
        {'.','.','7','.','.','.','2','4','.'},
        {'.','6','4','.','1','.','5','9','.'},
        {'.','9','8','.','.','.','3','.','.'},
        {'.','.','.','8','.','3','.','2','.'},
        {'.','.','.','.','.','.','.','.','6'},
        {'.','.','.','2','7','5','9','.','.'}};
    Solution s;
    s.solveSudoku(board);
    return 0;
}

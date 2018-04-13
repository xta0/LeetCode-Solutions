#include <iostream>
#include <vector>
#include <stdlib.h>     /* atoi */
using namespace std;

class Solution{
public:
    bool isValidSudoku(vector<vector<char>> &board){
        int col[9][10]={0};
        int row[9][10]={0};
        int block[9][10]={0};
        bool result = true;
        for (int i = 0; i < board.size(); ++i){
            for (int j = 0; j < board.size(); ++j){
                int block_index = i/3 * 3  + j/3;
                char c = board[i][j];
                if(c!='.'){
                    int num = atoi(&c);
                    if( !row[i][num] &&
                       !col[j][num] &&
                       !block[block_index][num]){
                        row[i][num] = 1;
                        col[j][num] = 1;
                        block[block_index][num]=1;
                    }else{
                        result = false;
                        break;
                    }
                }
            }
        }
        return result;
    }
};

int main()
{
    vector<vector<char>> board{
        {'.','8','7','6','5','4','3','2','1'},
        {'2','.','.','.','.','.','.','.','.'},
        {'3','.','.','.','.','.','.','.','.'},
        {'4','.','.','.','.','.','.','.','.'},
        {'5','.','.','.','.','.','.','.','.'},
        {'6','.','.','.','.','.','.','.','.'},
        {'7','.','.','.','.','.','.','.','.'},
        {'8','.','.','.','.','.','.','.','.'},
        {'9','.','.','.','.','.','.','.','.'}};
    Solution s;
    bool result = s.isValidSudoku(board);
    cout<<result<<endl;
    
    return 0;
}

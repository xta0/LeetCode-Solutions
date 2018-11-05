#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <unordered_set>
#include <unordered_map>
using namespace std;

//先记录矩阵行列中出现的0，分别记录行列放入集合
//对集合中的行列置0
//时间O(nxm), 空间O(n)
class Solution
{
  public:
    void setZeroes(vector<vector<int>> &matrix)
    {
        unordered_set<int> zrow;
        unordered_set<int> zcol;
        int h = matrix.size();
        int w = matrix[0].size();

        
        for (int i = 0; i < h; i++)
        {
            for (int j = 0; j < w; j++)
            {
                if (matrix[i][j] == 0)
                {
                    zrow.insert(i);
                    zcol.insert(j);
                }
            }
        }
        for (auto row : zrow)
        {
            for (int i = 0; i < w; i++)
            {
                matrix[row][i] = 0;
            }
        }
        for (auto col : zcol)
        {
            for (int i = 0; i < h; i++)
            {
                matrix[i][col] = 0;
            }
        }
    }
};

int main()
{

    return 0;
}
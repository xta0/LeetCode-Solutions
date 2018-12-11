#include <iostream>
#include <vector>
#include <string>
#include <array>
using namespace std;
/*
Solution: DP
Time: O(N^2)
Space: O(N^2)
*/
/*
状态：
DP[i][j]

原问题：
DP[m][n]，word1的m个字符编程word2的n个字符需要的最少步数

子问题：
DP[i][j]，word1的前i个字符变成word[j]的前j个字符需要的最少步数

方程：
if(w1[i] == w2[j]){
    dp[i][j] = dp[i-1][j-1]
}else{
    //如果要在i，j的位置继续满足子问题的定义，则要在
    //i-1和j-1的基础上依次尝试删除，插入，和替换
    dp[i][j] = min( dp[i-1][j],dp[i][j-1],dp[i-1][j-1]) + 1
}

*/
class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.size();
        int n = word2.size();
        vector<vector<int>> dp(m,vector<int>(n,0));
        for(int i=0;i<m;i++){
            dp[i][0] = i;
        }
        for(int j=0;j<n;j++){
            dp[0][j] = j;
        }
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                if(word1[i] == word2[j]){
                    dp[i][j] = dp[i-1][j-1];
                }else{
                    dp[i][j] = min(dp[i-1][j-1], min(dp[i-1][j],dp[i][j-1]))+1;
                }
            }
        }
        return dp[m-1][n-1];
    }
};

int main(){




    return 0;
}
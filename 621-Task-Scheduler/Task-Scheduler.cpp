#include <iostream>
#include <vector>
#include <array>
#include <string>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <unordered_set>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char,int> um;
        for(auto c:tasks){
            um[c]++;
        }
        int mostFrequncy = 0;
        for(auto &p : um){
            mostFrequncy = max(mostFrequncy,p.second);
        }
        int mostFrequncyTasks =0;
        for(auto &p : um){
            if(p.second == mostFrequncy){
                mostFrequncyTasks++;
            }
        }
        //公式
        int ans = (mostFrequncy-1)*(n+1) + mostFrequncyTasks;
        return max((int)tasks.size(),ans);

    }
};

int main(){




    return 0;
}
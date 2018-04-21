#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution{

public:
    vector<vector<int>> fourSum(vector<int> &nums, int target){
        numbers = nums;
        std::sort(numbers.begin(), numbers.end());
    }

private:
    map<int, vector<vector<int>>> dict;
    vector<int> numbers;

    vector<vector<int>> threeSum(vector<int> &nums){
        vector<vector<int>> threes;
        for (int i = 0; i < nums.size(); ++i){
            vector<vector<int>> twos;
            int x = numbers[i];
            if (dict[x].size() > 0){
                twos = dict[x];
            }else{
                twos = twoSum(i + 1, -x);
                dict[x] = twos;
            }
            if (twos.size() > 0){
                for (auto arr : twos){
                    arr.push_back(x);
                    threes.push_back(arr);
                }
            }
        }        
        return threes;
    }
    vector<vector<int>> twoSum(int begin, int target){
        vector<vector<int>> twos;
        int i = begin;
        int j = (int)numbers.size() - 1;
        while (i < j){
            int l = numbers[i];
            int r = numbers[j];
            if (l + r < target){
                i++;
            }
            else if (l + r == target){
                vector<int> tmp;
                tmp.push_back(l);
                tmp.push_back(r);
                twos.push_back(tmp);
                i++;
                j--;
                while (i < j && numbers[i] == numbers[i - 1]){
                    i++;
                }
                while (i < j && numbers[j] == numbers[j + 1]){
                    j--;
                }
            }
            else{
                j--;
            }
        }
        return twos;
    }
};

int main(){

    Solution s;
    //    vector<int> input = {-1,0,1,2,-1,-4};
    //    vector<int> input = {0,0,0,0};
    //    vector<int> input = {0,0,0};
    vector<int> input = {3, 0, -2, -1, 1, 2};
    s.threeSum(input);

    return 0;
}

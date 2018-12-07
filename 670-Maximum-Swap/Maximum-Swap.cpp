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

class Solution {
public:
    void swapRec(vector<int>& numbers, int start, int end){
        if(start == end){
            return;
        }
        int maxn = 0; int maxi = -1;
        for(int i=start; i<=end; ++i){
            if(numbers[i] > maxn){
                maxn = numbers[i];
                maxi = i;
            }
        }
        if(maxn==numbers[end]){
            swapRec(numbers,start,end-1);
        }else{
            swap(numbers[end],numbers[maxi]);
        }
    }
    int maximumSwap(int num) {
        vector<int> numbers;
        while(num != 0){
            int x = num % 10;
            numbers.push_back(x);
            num/=10;
        }
        swapRec(numbers,0,numbers.size()-1);
        
        int sum = 0;
        for(int i=0;i<numbers.size();i++){
            sum += pow(10,i)*numbers[i];
        }
        return sum;
    
    }
};

int main(){




    return 0;
}
#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;

class Solution {
    vector<pair<int, string>> dict ={
        {1000000000, "Billion"}, {1000000, "Million"}, {1000, "Thousand"}, {100, "Hundred"},
        {90, "Ninety"},{80, "Eighty"},{70, "Seventy"},{60, "Sixty"},
        {50, "Fifty"}, {40, "Forty"}, {30, "Thirty"}, {20, "Twenty"},
        {19, "Nineteen"}, {18, "Eighteen"}, {17, "Seventeen"}, {16, "Sixteen"}, {15, "Fifteen"},
        {14, "Fourteen"}, {13, "Thirteen"}, {12, "Twelve"}, {11, "Eleven"}, {10, "Ten"},
        {9, "Nine"},{8, "Eight"},{7, "Seven"},{6, "Six"}, {5, "Five"}, {4, "Four"}, {3, "Three"}, {2, "Two"}, {1, "One"}
    };
public:
    string numberToWords(int num) {
        if(num == 0){
            return "zero";
        }
        
        for(int i=0;i<dict.size();i++){
            int x = num / dict[i].first;
            if( x > 0 ){
                int r = num % dict[i].first;
                if(r==0){
                    if(num < 100){
                        return dict[i].second;
                    }else{
                        string str1 = numberToWords(x);
                        string str2 = dict[i].second;
                        return str1 +" " + str2;
                    }
                    
                }else{
                    string str1 = "";
                    if(dict[i].first < 100){
                        str1 = dict[i].second;
                    }else{
                        str1 = numberToWords(x) + " " + dict[i].second;
                    }
                    
                    string str2 = numberToWords(r);
                    return str1 + " " + str2;
                }

                
            }
        }
        return "";
    }
};

int main(){
    Solution s;
    cout<<s.numberToWords(100)<<endl;;
    
    
    
    return 0;
}

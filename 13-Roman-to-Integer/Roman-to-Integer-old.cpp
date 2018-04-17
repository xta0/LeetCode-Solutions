#include <iostream>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    int romanToInt(string s)
    {
        const unordered_map<string, int> m = {
            {"I" , 1},
            {"IV" ,4},
            {"V",  5},
            {"IX", 9},
            {"X",  10},
            {"XL", 40},
            {"L", 50},
            {"XC",90},
            {"C", 100},
            {"CD",400},
            {"D", 500},
            {"CM",900},
            {"M", 1000}};
        
        int result = 0;
        for(int i=0; i<s.length(); ++i ){
            string s1 = string(1,s[i]);
            string s2 = i+1 < s.length() ? string(1,s[i+1]):"";
            string ss = s1+s2;
            if(m.find(ss) == m.end()){
                result += m.find(s1)->second;
            }else{
                result += m.find(ss)->second;
                i += 1;
            }
        }
        return result;
    }
};

int main()
{
    Solution s;
    cout<<s.romanToInt("III")<<endl;
    cout<<s.romanToInt("IV")<<endl;
    cout<<s.romanToInt("IX")<<endl;
    cout<<s.romanToInt("LVIII")<<endl;
    cout<<s.romanToInt("MCMXCIV")<<endl;
    
    
    return 0;
}

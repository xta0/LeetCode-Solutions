#include <iostream>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    int romanToInt(string s)
    {
        const unordered_map<char, int> m = {
            {'I' , 1},
            {'V',  5},
            {'X',  10},
            {'L', 50},
            {'C', 100},
            {'D', 500},
            {'M', 1000}};
        
        int result = 0;
        for(int i=0; i<s.length(); ++i ){
            int x1 = m.find(s[i])->second;
            int x2 = i+1 < s.length() ? m.find(s[i+1])->second:0;
            if(x1 < x2){
                result -= x1;
            }else{
                result += x1;
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

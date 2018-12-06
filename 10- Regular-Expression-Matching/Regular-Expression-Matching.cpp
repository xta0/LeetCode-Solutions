#include <iostream>
#include <vector>
#include <string>
using namespace std;

/*
 */
class Solution
{
  public:
    bool isMatch(string s, string p)
    {
        if (p.empty()){
            return s.empty();
        }
        //p=".", p="x"
        if (p.size() == 1){
            return (s.size() == 1) && (s[0] == p[0] || p[0] == '.');
        }
        if (p[1] != '*'){
            if (s.empty()){
                return false;
            }
            if (s[0] == p[0] || p[0] == '.'){
                return isMatch(s.substr(1), p.substr(1));
            }
            else{
                return false;
            }
        }

        /*
         p[1]=='*'
         s="", p="b*" --> isMatch(s,b.substr(2));
         s="x",p="b*" --> isMatch(s,b.substr(2));
         s="b",p="b*" || s="b",p=".*" -->s=s.substr(1) -->isMatch(s,b.substr(2))
         */
        while (!s.empty() && (p[0] == s[0] || p[0] == '.')){
            //s="a", p="a*a"
            if (isMatch(s, p.substr(2))){
                return true;
            }
            s = s.substr(1);
        }
        return isMatch(s, p.substr(2));
    }
};

int main()
{

    return 0;
}

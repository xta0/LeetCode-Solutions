#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution
{
  public:
    int lengthOfLastWord(string s)
    {
        if (s.length() == 0){
            return 0;
        }
        int l = 0, r = s.length() - 1;
        //skip spaces
        while(l<=r && s[r] == ' '){
            r--;
        }
        int count = 0;
        while (l <= r){
            if (s[r] == ' '){
                break;
            }
            count++;
            r--;
        }
        return count;
    }
};

int main()
{

    return 0;
}
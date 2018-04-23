#include <string>
#include <iostream>
using namespace std;

class Solution
{
public:
    int strStr(string haystack, string needle){
        if(needle.length() == 0){
            return 0;
        }
        int index = -1;
        int m = haystack.length();
        int n = needle.length();
        for (int i = 0; i <m-n+1; ++i)
        {
            if (haystack[i] == needle[0])
            {
                index = i;
                for (int j = 0; j <n; ++j){
                    if (needle[j] != haystack[i + j]){
                        index = -1;
                        break;
                    }
                }
                if (index != -1){
                    return i;
                }
            }
        }
        return index;
    }
};

int main(){
    return 0;
}

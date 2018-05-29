#include <iostream>
#include <map>
#include <string>
#include <algorithm>

using namespace std;

//滑动窗口
//一个map+两个指针
//动态trace字符串的范围
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int strLen = (int)s.length();
        int len = 0; map<char, int> dict;
        for(int l=0, r=0; r<strLen; ++r){
            char c = s[r];
            if(dict.find(c) != dict.end()){
                /*
                遇到重复字符，更新滑动窗口的左边界为：
                1. 窗口内重复字符的下一个位置
                2. 左边界不能回退，因此使用max函数
                */
                l=max(l,dict[c]+1); 
            }
            //更新出现字符的index
            dict[c] = r;
            /*
            总长度 = max(滑动窗口右边界 - 左边界 +1 )
            */
            len = max(len,r-l+1);
        }
        return len;
    }
};
int main(){
    Solution s;
    cout<<s.lengthOfLongestSubstring("abcaecbb")<<endl;

    return 0;
}
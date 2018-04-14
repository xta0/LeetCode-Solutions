#include <iostream>
#include <string>
using namespace std;

int main(){
    string  s("abcaxdxnd");
    int pos=0,max=0;
    for(int i=0;i<s.length();++i){
        char c = s[i];
        int count = 0;
        
        for(int j=i+1; j<s.length(); ++j){
            char next = s[j];
            if(c!=next){
                count++;
            }else{
                break;
            }
        }
        if(count > max){
            max = count;
            pos = i;
        }
    }
    cout<<"pos: "<<pos<<", length:"<<max<<endl;

    return 0;
}
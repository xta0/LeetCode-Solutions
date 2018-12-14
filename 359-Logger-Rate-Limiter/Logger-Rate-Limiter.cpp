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

class Logger {
    unordered_map<string,int> um;
public:
    /** Initialize your data structure here. */
    Logger() {
        
    }
    
    /** Returns true if the message should be printed in the given timestamp, otherwise returns false.
     If this method returns false, the message will not be printed.
     The timestamp is in seconds granularity. */
    bool shouldPrintMessage(int timestamp, string message) {
        
        if(um.count(message)){
            int t = um[message];
            if(timestamp - t < 10){
                return false;
            }else{
                um[message] = timestamp;
            }
        }else{
            um[message] = timestamp;
        }
        return true;
    }
};

int main(){
    
    Logger lg;
    cout<<lg.shouldPrintMessage(1,"foo")<<endl;
    cout<<lg.shouldPrintMessage(2,"bar")<<endl;
    cout<<lg.shouldPrintMessage(3,"foo")<<endl;
    cout<<lg.shouldPrintMessage(8,"bar")<<endl;
    cout<<lg.shouldPrintMessage(10,"foo")<<endl;
    cout<<lg.shouldPrintMessage(11,"foo")<<endl;
    
    
    
    return 0;
}

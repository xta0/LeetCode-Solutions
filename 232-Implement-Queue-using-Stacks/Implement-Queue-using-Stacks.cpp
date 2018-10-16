#include <iostream>
#include <vector>
#include <string>
#include <stack>

using namespace std;


class MyQueue {
private: 
    stack<int> s1;
    stack<int> s2;

public:
    /** Initialize your data structure here. */
    MyQueue() {
        
    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        s1.push(x);
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        while(!s1.empty()){
            int x = s1.top();
            s2.push(x);
            s1.pop();
        }
        int ret = s2.top();
        s2.pop();
        while(!s2.empty()){
            int x = s2.top();
            s1.push(x);
            s2.pop();
        }
        return ret;
    }
    
    /** Get the front element. */
    int peek() {
        while(!s1.empty()){
            int x = s1.top();
            s2.push(x);
            s1.pop();
        }
        int ret = s2.top();
        while(!s2.empty()){
            int x = s2.top();
            s1.push(x);
            s2.pop();
        }
        return ret;
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return s1.empty();
    }
};

int main(){




    return 0;
}
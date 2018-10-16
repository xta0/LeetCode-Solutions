#include <iostream>
#include <vector>
#include <string>
#include <queue>

using namespace std;

class MyStack {
private:
    queue<int> q1;
    queue<int> q2;
public:
    /** Initialize your data structure here. */
    MyStack() {
        
    }
    
    /** Push element x onto stack. */
    void push(int x) {
        q1.empty()?q2.push(x):q1.push(x);
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        queue<int>& fq = q1.size()>0?q1:q2;
        queue<int>& eq = q1.size()==0?q1:q2;
        int ret = 0;

        while(!fq.empty()){
            int x = fq.front();
            fq.pop();
            if(fq.empty()){
                ret = x;
            }else{
                eq.push(x);
            }
        }
        return ret;
    }
    
    /** Get the top element. */
    int top() {
        int ret = 0;
        queue<int>& fq = q1.size()>0?q1:q2;
        queue<int>& eq = q1.size()==0?q1:q2;
        while(!fq.empty()){
            int x = fq.front();
            fq.pop();
            if(fq.empty()){
                ret = x;
            }
            eq.push(x);
        }
        return ret;
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return q1.empty() && q2.empty();       
    }
};

int main(){




    return 0;
}
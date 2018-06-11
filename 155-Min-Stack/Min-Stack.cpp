#include <iostream>
#include <stack>
using namespace std;

class MinStack {
public:
    stack<int> stk;
    stack<int> stk_min;
    /** initialize your data structure here. */
    void push(int x) {
        if(stk_min.empty()){
            stk_min.push(x);
        }else{
            int min = getMin();
            if(x <= min){
                stk_min.push(x);
            }
        }
        stk.push(x);
    }
    
    void pop() {
        if(!stk.empty()){
            if(!stk_min.empty()){
                int x = top();
                if(x == stk_min.top()){
                    stk_min.pop();
                }
            }
            stk.pop();
        }
    }
    
    int top() {
        return stk.top();
    }
    
    int getMin() {
        return stk_min.top();
    }
};

int main(){
    MinStack stack;
    stack.push(0);
    stack.push(1);
    stack.push(0);
    cout<<stack.getMin()<<endl;
    stack.pop();
    cout<<stack.getMin()<<endl;

    return 0;
}

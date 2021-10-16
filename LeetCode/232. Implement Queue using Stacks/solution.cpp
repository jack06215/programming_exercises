#include <stack>
#include <iostream>

using namespace std;

class MyQueue {
public:
    MyQueue() {
        
    }
    
    void push(int x) {
        stk.push(x);
    }
    
    int pop() {
        int val = peek();
        stk_back.pop();
        return val;
    }
    
    int peek() {
        if (stk_back.empty()) {
            while (!stk.empty()) {
                stk_back.push(stk.top());
                stk.pop();
            }
        }
        return stk_back.top();
    }
    
    bool empty() {
        return stk.empty() && stk_back.empty();
    }
private:
    stack<int> stk;
    stack<int> stk_back;
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
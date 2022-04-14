#include <stack>

using namespace std;

class MyQueue {
public:
    MyQueue() { }

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
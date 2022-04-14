#include <limits>
#include <stack>

using namespace std;

class MinStack {
public:
    MinStack() : min_val(numeric_limits<int>::max()) {}

    void push(int val) {
        // push twice if val is min
        if (val <= min_val) {
            st.push(min_val);
            min_val = val;
        }
        st.push(val);
    }

    void pop() {
        // pop twice if val is min
        int t = st.top(); st.pop();
        if (t == min_val) {
            min_val = st.top(); st.pop();
        }
    }

    int top() {
        return st.top();
    }

    int getMin() {
        return min_val;
    }

private:
    int min_val;
    stack<int> st;
};
#include <stack>
using namespace std;

class MinStack {
public:
    MinStack() {}

    void push(int x) {
        s.push(x);
        sMin.push(sMin.empty()?x:min(x, sMin.top()));
    }

    void pop() {
        s.pop();
        sMin.pop();
    }

    int top() {
        return s.top();
    }

    int getMin() {
        return sMin.top();
    }

private:
    stack<int> s;
    stack<int> sMin;
};

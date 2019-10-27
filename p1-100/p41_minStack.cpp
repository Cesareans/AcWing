#include <stack>
using namespace std;

class MinStack {
public:
    MinStack() {}

    void push(int x) {
        s.push(x);
        // sMin.push(sMin.empty()?x:min(x, sMin.top())); // 普通做法，最小栈与普通栈一致
        if(sMin.empty() || sMin.top() >= x) sMin.push(x); // 单调栈做法，仅保存最小值，注意等于时也需要存
    }

    void pop() {
        if(s.top() == sMin.top()) sMin.pop();
        s.pop();
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

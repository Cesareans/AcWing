#include <iostream>
using namespace std;

const int N = 1000010;

int lstack[N], rstack[N], sumStack[N], maxStack[N];
int lt = 0, rt = 0;

void lInsert(int v) {
    lstack[++lt] = v;
    sumStack[lt] = v + sumStack[lt - 1];
    maxStack[lt] = lt <= 1 ? sumStack[lt] : max(sumStack[lt], maxStack[lt - 1]);
}

int main() {
    int n;
    scanf("%d", &n);
    char cmd[2];
    int v;
    for (int i = 0; i < n; ++i) {
        scanf("%s", cmd);
        switch (*cmd) {
            case 'I': {
                scanf("%d", &v);
                lInsert(v);
                break;
            }
            case 'Q': {
                scanf("%d", &v);
                printf("%d\n", maxStack[v]);
                break;
            }
            case 'D':
                if(lt > 0) --lt;
                break;
            case 'L':
                if (lt > 0) rstack[++rt] = lstack[lt--];
                break;
            case 'R':
                if (rt > 0) lInsert(rstack[rt--]);
                break;
        }
    }
    return 0;
}

/*
#include <iostream>

using namespace std;

const int N = 1000010;

class stack {
public:
    void push(int i) {
        arr[++idx] = i;
    }

    void pop() {
        --idx;
    }

    int top() {
        return arr[idx];
    }

    bool empty() {
        return idx == -1;
    }

    int operator[](int i) {
        return arr[i];
    }

    int size(){
        return idx+1;
    }

private:
    int idx = -1;
    int arr[N];
};

stack lstack, rstack, sumStack, maxStack;
void lInsert(int v){
    lstack.push(v);
    sumStack.push(sumStack.empty() ? v : v + sumStack.top());
    maxStack.push(maxStack.empty()?sumStack.top():max(sumStack.top(), maxStack.top()));
}
void lDelete(){
    if(!lstack.empty()){
        lstack.pop();
        sumStack.pop();
        maxStack.pop();
    }
}
static int x=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();
int main() {

    int n;
    cin >> n;
    char cmd;
    int v;
    for (int i = 0; i < n; ++i) {
        cin >> cmd;
        switch (cmd) {
            case 'I': {
                cin >> v;
                lInsert(v);
                break;
            }
            case 'Q': {
                cin >> v;
                cout << maxStack[v] << endl;
                break;
            }
            case 'D':
                lDelete();
                break;
            case 'L':
                if(!lstack.empty()){
                    rstack.push(lstack.top());
                    lDelete();
                }
                break;
            case 'R':
                if (!rstack.empty()) {
                    lInsert(rstack.top());
                    rstack.pop();
                }
                break;
        }
    }
    return 0;
}
 */
#include <iostream>
#include <vector>
using namespace std;

const int N = 30;
int stack[N];
vector<int> serial;

int cnt = 20;

void train(int si, int tr, int n){
    if(!cnt) return;
    if(serial.size() == n){
        --cnt;
        for(int i : serial) cout<<i;
        cout << endl;
        return;
    }
    if (si > 0){
        serial.push_back(stack[si--]);
        train(si, tr, n);
        stack[++si] = *(serial.end()-1);
        serial.pop_back();
    }
    if(tr <= n){
        stack[++si] = tr ++;
        train(si, tr, n);
    }
}

int main(){
    int n;
    cin >> n;
    train(0, 1, n);
    return 0;
}
#include <iostream>
#include <queue>
#include <cmath>

using namespace std;
const int N = 100010;
int length[N];

int main() {
    priority_queue<int> pq;
    int n, m, q, u, v, t, tl, ll, cnt = 0;
    cin >> n >> m >> q >> u >> v >> t;
    double p = (double) u / v;
    for (int i = 0; i < n; ++i) {
        cin >> tl;
        pq.push(tl);
    }
    for (int i = 0; i < m; ++i) {
        int sl = pq.top();
        pq.pop();
        if(++cnt%t==0){
            cout << sl << " ";
        }
        ll = floor(p*sl);
        pq.push(sl - ll);
        pq.push(ll);
    }
    cout << endl;
    cnt = 0;
    while (!pq.empty()){
        if(++cnt%t==0) cout << pq.top() << " ";
        pq.pop();
    }

    return 0;
}
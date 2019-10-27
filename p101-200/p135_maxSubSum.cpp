#include <iostream>
#include <queue>
#include <climits>

using namespace std;
typedef long long ll;
const int N = 300010;
ll pfs[N];

int main() {
    ios::sync_with_stdio(false);
    int n, m,t;
    ll res = LONG_MIN;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        cin >> t;
        pfs[i] = pfs[i - 1] + t;
    }
    deque<pair<ll, int>> minq;
    minq.emplace_back(0,0);
    for (int i = 1; i <= n; ++i) {
        if(i - minq.front().second > m) minq.pop_front();
        res = max(res, pfs[i] - minq.front().first);
        while (!minq.empty() && (minq.back().first >= pfs[i])) minq.pop_back();
        minq.emplace_back(pfs[i], i);
    }
    cout << res << endl;
    return 0;
}
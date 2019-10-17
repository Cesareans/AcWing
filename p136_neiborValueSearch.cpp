#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>

using namespace std;

static int x = []() {
    ios::sync_with_stdio(false);
    return 0;
}();

typedef long long ll;
typedef pair<ll, int> pli;


const int N = 100010;
int idx[N], l[N], r[N];
pli arr[N];
vector<pli> res;

int main() {
    int n = 0;
    cin >> n;
    res.reserve(n + 10);
    for (int i = 1; i <= n; ++i) {
        cin >> arr[i].first;
        arr[i].second = i;
    }
    sort(arr + 1, arr + 1 + n);
    for (int i = 1; i <= n; ++i) {
        l[i] = i - 1;
        r[i] = i + 1;
        idx[arr[i].second] = i;
    }
    arr[0] = {INT_MAX, 0};
    arr[n+1] = {INT_MIN, 0};
    ll pre, post;
    do {
        pre = abs(arr[l[idx[n]]].first - arr[idx[n]].first);
        post = abs(arr[r[idx[n]]].first - arr[idx[n]].first);
        if (pre < post) {
            res.emplace_back(pre, arr[l[idx[n]]].second);
        } else if(pre > post) {
            res.emplace_back(post, arr[r[idx[n]]].second);
        }else{
            res.emplace_back(post, arr[l[idx[n]]].first < arr[r[idx[n]]].first?arr[l[idx[n]]].second:arr[r[idx[n]]].second);
        }
        r[l[idx[n]]] = r[idx[n]];
        l[r[idx[n]]] = l[idx[n]];
    } while (--n > 1);
    for (int i = res.size() - 1; i >= 0; --i) {
        cout << res[i].first << " " << res[i].second << endl;
    }
    return 0;
}
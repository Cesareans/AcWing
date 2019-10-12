#include <iostream>
#include <set>

using namespace std;

const int N = 10010;
int arr[N];

int main() {
    int n, p, h, m;
    cin >> n >> p >> h >> m;
    int a, b;
    set<pair<int, int>> s;
    for (int i = 0; i < m; ++i) {
        cin >> a >> b;
        if(a > b) swap(a, b);
        if (!s.count({a, b})) {
            s.insert({a, b});
            arr[a + 1]--;
            arr[b]++;
        }
    }
    arr[1] = h;
    for (int i = 1; i <= n; ++i) {
        arr[i] = arr[i - 1] + arr[i];
        cout << arr[i] << endl;
    }
    return 0;
}
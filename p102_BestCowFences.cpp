#include <iostream>

using namespace std;

const int N = 100010;
double a[N], sum[N], m[N];

int main() {
    int n, f;
    cin >> n >> f;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    double eps = 1e-5;
    double l = -1e10, r = 1e10;
    while (r - l > eps) {
        double mid = (r + l) / 2;
        for (int i = 1; i <= n; ++i) {
            m[i] = a[i] - mid;
            sum[i] = sum[i - 1] + m[i];
        }
        double ans = -1e10;
        double minValue = 1e10;
        for (int i = f; i <= n; ++i) {
            minValue = min(minValue, sum[i - f]);
            ans = max(ans, sum[i] - minValue);
            if (ans > 0) break;
        }

        if (ans > 0)l = mid; else r = mid;
    }
    cout<<int(r*1000)<<endl;
    return 0;
}
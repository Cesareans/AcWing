#include <iostream>
#include <algorithm>
#include <limits>

using namespace std;

const int N = 100010;
int h[N], stack[N][2], sdx = 0, ldx[N], rdx[N];
static int x = []() {
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    stack[0][0] = INT_MIN;
    return 0;
}();
void iterate(int size, int (&arr)[N]) {
    sdx = 0;
    for (int i = 1; i <= size; ++i) {
        while (sdx > 0 && h[i] <= stack[sdx][0]) sdx--;
        if (h[i] > stack[sdx][0]) {
            stack[++sdx][0] = h[i];
            stack[sdx][1] = i;
        }
        int idx = sdx;
        while (stack[idx][0] >= h[i]) --idx;
        arr[i] = stack[idx][1];
    }
}


int main() {
    int n;

    while (cin >> n, n) {
        long long m = INT_MIN;
        for (int i = 1; i <= n; ++i) cin >> h[i];
        iterate(n, ldx);
        reverse(h + 1, h + n + 1);
        iterate(n, rdx);
        for(int i = 1 ; i <= n ; ++i) m = max(m, h[i] * (long long)(n-rdx[i]-ldx[n+1-i]));
        cout << m << endl;
    }
    return 0;
}
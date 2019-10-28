#include <iostream>
#include <cmath>

using namespace std;


const int N = 1000010;
const int P = 131;
typedef unsigned long long ull;

static int x = []() {
    ios::sync_with_stdio(false);
    return 0;
}();

char c[N];
ull hs[N], p[N];

int main() {
    cin >> (c + 1);
    p[0] = 1;
    for (int i = 1; c[i] != 0; ++i) {
        int v = c[i] - 'a' + 1;
        hs[i] = hs[i - 1] * P + v;
        p[i] = p[i - 1] * P;
    }
    int n, l1, l2, r1, r2;
    cin >> n;
    while (n--) {
        cin >> l1 >> r1 >> l2 >> r2;
        ull lhash = (hs[r1] - hs[l1 - 1] * p[r1 - l1 + 1]);
        ull rhash = (hs[r2] - hs[l2 - 1] * p[r2 - l2 + 1]);
        cout << (lhash == rhash?"Yes":"No") << endl;
    }
    return 0;
}
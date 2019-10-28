#include <iostream>

using namespace std;

const int size = 5002;
// 注意要开到全局变量里，如果放在main里，那该变量将会被分配在栈中，而一般栈的大小配置为4MB
// 实际上该数组大小为100M，故将会产生分配异常
int arr[size][size];

int main() {
    int n, r;
    cin >> n >> r;
    // 因为可能r要比当前最大的目标的坐标要大，所以对最大mx与my先赋值r方便后续处理
    int mx = r, my = r;
    int tx, ty, tv;
    for (int i = 0; i < n; ++i) {
        cin >> tx >> ty >> tv;
        // 将坐标加一，坐标带0的都为0，方便后续对边界的判定
        mx = max(++tx, mx);
        my = max(++ty, my);
        arr[tx][ty] += tv;
    }
    for (int i = 1; i <= mx; ++i) {
        for (int j = 1; j <= my; ++j) {
            arr[i][j] = arr[i - 1][j] + arr[i][j - 1] - arr[i - 1][j - 1] + arr[i][j];
        }
    }
    int res = 0;
    for (int i = 1; i <= mx - r + 1; ++i) {
        for (int j = 1; j <= my - r + 1; ++j) {
            res = max(res, arr[i + r - 1][j + r - 1] + arr[i - 1][j - 1] - arr[i + r - 1][j - 1] - arr[i - 1][j + r - 1]);
        }
    }
    cout << res;
    return 0;
}
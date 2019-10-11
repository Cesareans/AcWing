#include <cstdio>
#include <algorithm>
#include <iostream>

using namespace std;

const int m = 1 << 30;
// 利用偏移量进行周围枚举
int dx[5] = {0, -1, 0, 1, 0}, dy[5] = {0, 0, 1, 0, -1};

void change(char **arr, int x, int y) {
    for (int i = 0; i < 5; ++i) {
        int xo = x + dx[i], yo = y + dy[i];
        if (xo >= 0 && xo < 5 && yo >= 0 && yo < 5) {
            arr[xo][yo] ^= 1;
        }
    }
}

void copy(char **from, char **to) {
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {
            to[i][j] = from[i][j];
        }
    }
}

/*
 * 当第一行的状态不在可以主动修改时，其余的行也依次确定，故可以以1<<5的复杂度枚举第一行的状态，然后依次根据上一列进行主动修改
 */
int iter(char **arr) {
    char **backup = new char *[5];
    for (int i = 0; i < 5; ++i) backup[i] = new char[5];
    copy(arr, backup);

    int res = m;
    for (int i = 0; i < 1 << 5; ++i) {
        copy(backup, arr);
        int time = 0;

        for (int j = 0; j < 5; ++j) {
            if (i & 1 << j) {
                change(arr, 0, j);
                time++;
            }
        }

        for (int j = 1; j < 5; ++j) {
            for (int k = 0; k < 5; ++k) {
                if (arr[j - 1][k] == '0') {
                    change(arr, j, k);
                    time++;
                }
            }
        }

        int success = 1;
        for (int j = 0; j < 5; ++j) {
            if (arr[4][j] == '0') success = 0;
        }
        if (success) res = min(res, time);
    }
    return res <= 6 ? res : -1;
}

int main() {
    int n;
    char **arr = new char *[5];
    for (int i = 0; i < 5; ++i) {
        arr[i] = new char[5];
    }
    cin >> n;
    for(int k = 0 ; k < n ; ++k){
        for (int i = 0; i < 5; ++i) {
            for (int j = 0; j < 5; ++j){
                cin>>arr[i][j];
            }
        }
        cout<< iter(arr) << endl;
    }
    return 0;
}
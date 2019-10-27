#include <cstdio>
#include <vector>

using namespace std;

/*
 * 两种回溯
 * 一种是使用引用vector记录，为了减少复制支出需要使用引用，注意往下走回来后需要进行状态恢复
 * 另一种是使用int的bit记录，直接传值，不用进行状态恢复
 */

// With Vector backtrace method
void ExponentEnum(vector<int> &vec, int n, int i) {
    if (i > n) {
        for (int k : vec) {
            printf("%d ", k);
        }
        printf("\n");
        return;
    }
    vec.push_back(i);
    ExponentEnum(vec, n, i + 1);
    vec.pop_back();
    ExponentEnum(vec, n, i + 1);
}


// 因为题目的位数范围在1-15间，可考虑使用一个int，使用位进行记录

void ExponentEnum(int record, int n, int i) {
    if (i > n) {
        for (int j = 1; j <= n; ++j) {
            if ((record >> j) & 1) printf("%d ", j);
        }
        printf("\n");
        return;
    }
    //不要i
    ExponentEnum(record, n, i + 1);
    //要i
    ExponentEnum(record | 1 << (i), n, i + 1);
}


//void ExponentEnum(int n) {
//    vector<int> vec;
//    ExponentEnum(vec, n, 1);
//}

void ExponentEnum(int n) {
    ExponentEnum(0, n, 1);
}
int main() {
    int n;
    scanf("%d", &n);
    ExponentEnum(n);
    return 0;
}
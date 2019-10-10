#include <cstdio>
/*
 * 运用位运算进行快速幂计算
 */
int main() {
    int a, b, p;
    scanf("%d %d %d", &a, &b, &p);
    int res = 1 % p;
    while (b) {
        if (b & 1) res = (long long) res * a % p;
        a = (long long) a * a % p;
        b >>= 1;
    }
    printf("%d", res);
    return 0;
}
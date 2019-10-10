#include <cstdio>

/*
 * 将乘法分解为加法，运用快速幂进行二分
 */
int main(){
    long long a, b, p;
    scanf("%lld %lld %lld", &a, &b, &p);
    long long res = 0;
    while (b){
        if(b&1) res = (res + a) % p;
        a = 2*a%p;
        b>>=1;
    }
    printf("%lld", res);
    return 0;
}
#include <iostream>
#include <algorithm>
#include <limits.h>
using namespace std;

const int N = 1000010;

int stkl[N], stkr[N], tl, tr;
int s[N], f[N];

void push_left(int x){
    stkl[++tl] = x;
    s[tl] = s[tl-1] + x;
    f[tl] = max(f[tl-1], s[tl]);
}

int main(){
    int n;
    scanf("%d", &n);
    f[0] = INT_MIN;
    while (n--){
        char str[2];
        int x;
        scanf("%s", str);
        if(*str == 'I'){
            scanf("%d", &x);
            push_left(x);
        } else if(*str == 'D'){
            if(tl > 0) tl--;
        } else if(*str == 'L'){
            if(tl > 0) stkr[++tr] = stkl[--tl];
        } else if(*str == 'R'){
            if(tr > 0) push_left(stkr[tr--]);
        }else{
            scanf("%d", &x);
            printf("%d\n", f[x]);
        }
    }
    return 0;
}

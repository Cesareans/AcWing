#include <iostream>
#include <algorithm>
#include <memory>
using namespace std;

// 三柱汉诺塔种数
int hanoi3pillar(int n){
    int * arr = new int[n+1];
    arr[1] = 1;
    for(int i = 2 ; i <= n ; ++i){
        // = arr[i-1] + 1 + arr[i-1]
        // 先把i-1个柱子移到中间，再把第i个柱子移到最后，再把i-1个柱子移到最后
        arr[i] = 1 + 2*arr[i-1];
    }
    return arr[n];
}

// 四柱汉诺塔种数
int hanoi4pillar(int n){
    int * pillar3 = new int[n + 1];
    pillar3[1] = 1;
    for(int i = 2 ; i <= n ; ++i){
        pillar3[i] = 1 + 2 * pillar3[i - 1];
    }

    int * pillar4 = new int[n+1];
    for(int i = 0 ; i < n+1; ++i){
        pillar4[i] = 1<<28;
    }
    pillar4[1] = 1;
    for(int i = 2 ; i <= n ; ++i){
        for(int j = 0; j < n; ++j){
            pillar4[i] = min(pillar4[i], pillar4[j] * 2 + pillar3[i-j]);
        }
    }
    delete[] pillar3;
    int res = pillar4[n];
    delete[] pillar4;

    return res;
}

//int main(){
//    for(int i = 1 ; i <= 12 ; ++i){
//        cout<<hanoi4pillar(i)<<endl;
//    }
//    return 0;
//}

int main(){
    const int n = 12;
    int * pillar3 = new int[n + 1];
    pillar3[1] = 1;
    for(int i = 2 ; i <= n ; ++i){
        pillar3[i] = 1 + 2 * pillar3[i - 1];
    }

    int * pillar4 = new int[n+1];
    for(int i = 0 ; i < n+1; ++i){
        pillar4[i] = 1<<28;
    }
    pillar4[1] = 1;
    for(int i = 2 ; i <= n ; ++i){
        for(int j = 0; j < n; ++j){
            pillar4[i] = min(pillar4[i], pillar4[j] * 2 + pillar3[i-j]);
        }
    }
    for(int i = 1; i <= 12; ++i){
        cout<<pillar4[i]<<endl;
    }

    delete[] pillar3;
    delete[] pillar4;
    return 0;
}
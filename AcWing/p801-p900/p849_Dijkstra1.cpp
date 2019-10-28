#include <iostream>
#include <memory.h>
using namespace std;
const int N = 510;

int wgt[N][N];
int dist[N], sign[N];
int main(){
    memset(wgt, 0x3f, sizeof(wgt));
    memset(dist, 0x3f, sizeof(dist));
    int n = 0, m = 0;
    cin >> n >> m;
    int x = 0, y = 0, z = 0;
    while(m--){
        cin >> x >> y >> z;
        wgt[x][y] = min(wgt[x][y], z);
    }
    dist[1] = 0;
    for(int i = 1 ; i < n; ++i){
        int idx = 0;
        for(int j = 1; j < n ;++j){
            if(!sign[j] && dist[idx] > dist[j]) {
                idx = j;
                break;
            }
        }
        sign[idx] = 1;
        for(int j = 1 ; j <= n ;++j){
            dist[j] = min(dist[j], dist[idx] + wgt[idx][j]);
        }
    }
    cout<< dist[n] != 0x3f3f3f3f?dist[n]:-1;
    return 0;
}
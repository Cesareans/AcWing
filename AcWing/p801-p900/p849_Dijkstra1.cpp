#include <iostream>
#include <memory.h>

using namespace std;

const int N = 510;

int wgt[N][N];
int dist[N], visited[N];

int main() {
    memset(wgt, 0x3f, sizeof(wgt));
    memset(dist, 0x3f, sizeof(dist));
    int n = 0, m = 0, x = 0, y = 0, z = 0;
    cin >> n >> m;
    while(m--){
        cin >> x >> y >> z;
        wgt[x][y] = min(wgt[x][y], z);
    }
    dist[1] = 0;
    for(int i = 1 ; i <= n ;++i){
        int idx = 0;
        for(int j = 1; j <= n; ++j){
            if(!visited[j] && dist[j] < dist[idx]){
                idx = j;
            }
        }
        visited[idx] = 1;
        for(int j = 1; j <= n; ++j){
            dist[j] = min(dist[j], dist[idx] + wgt[idx][j]);
        }
    }
    cout << (dist[n] == 0x3f3f3f3f?-1:dist[n]);
    return 0;
}
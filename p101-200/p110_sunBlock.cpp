#include <iostream>
#include <algorithm>

using namespace std;

const int N = 2510;
pair<int, int> cow[N];
pair<int, int> spf[N];

int main() {
    int c, l;
    cin >> c >> l;

    for (int i = 0; i < c; ++i) cin >> cow[i].first >> cow[i].second;
    for (int i = 0; i < l; ++i) cin >> spf[i].first >> spf[i].second;
    sort(cow, cow + c);
    sort(spf, spf+l);
    int cnt = 0, sdx = 0;
    for(int i = 0 ; i < c ; ++i){
        while(cow[i].first > spf[sdx].first || spf[sdx].second == 0) sdx++;
        if(cow[i].first <= spf[sdx].first && cow[i].second >= spf[sdx].first){
            cnt++;
            spf[sdx].second--;
        }
    }
    cout << cnt << endl;
    return 0;
}
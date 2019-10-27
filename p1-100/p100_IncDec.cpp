#include <iostream>
using namespace std;

const int N = 100010;
int arr[N];

/*
 * 我透，差分太难了
 */
int main(){
    int n;
    cin >> n;
    long neg = 0, pos = 0;
    for(int i = 0 ; i < n; ++i){
        cin >> arr[i];
        if(i){
            int t = arr[i]-arr[i-1];
            neg += t < 0 ? -t : 0;
            pos += t > 0 ? t : 0;
        }
    }
    cout<<max(neg,pos) << endl;
    cout<<abs(neg-pos) + 1;

    return 0;
}
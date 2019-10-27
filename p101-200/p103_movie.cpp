#include <iostream>
using namespace std;

const int MAX = 200010;

int N[MAX], M[MAX][2];
/*
 * O(MN)
 * TLE
 */
int main(){
    int n,m,v,s;
    cin >> n;
    for(int i = 0 ; i < n ; ++i){
        cin >> N[i];
    }
    cin >> m;
    for(int i = 0 ; i < m ; ++i)cin >> M[i][0];
    for(int i = 0 ; i < m ; ++i)cin >> M[i][1];

    int mid = 0, mHappy =0,mLessHappy = 0,happy = 0,lessHappy=0;
    for(int i = 0 ; i < m ; ++i){
        happy = 0;
        lessHappy = 0;
        for(int j = 0 ; j < n ; ++j){
            if(M[i][0] == N[j]) happy++;
            if(M[i][1] == N[j]) lessHappy++;
        }
        if(happy > mHappy){
            mid = i;
            mHappy = happy;
            mLessHappy = lessHappy;
        }else if(happy >= mHappy && lessHappy > mLessHappy){
            mid = i;
            mLessHappy = lessHappy;
        }
    }
    cout<<mid + 1;
    return 0;
}
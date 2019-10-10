#include <cstdio>
#include <vector>

using namespace std;

void ExponentEnum(vector<int> &vec, int n, int m, int ni, int mi) {
    if(mi == m){
        for(int k : vec) printf("%d ", k);
        printf("\n");
        return;
    }
    if (ni > n) return;
    vec.push_back(ni);
    ExponentEnum(vec, n, m, ni + 1, mi + 1);
    vec.pop_back();
    ExponentEnum(vec, n, m, ni + 1, mi);
}

void ExponentEnum(int n, int m) {
    vector<int> vec;
    vec.reserve(m);
    ExponentEnum(vec, n, m, 1, 0);
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    ExponentEnum(n, m);
    return 0;
}
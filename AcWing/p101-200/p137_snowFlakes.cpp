#include <iostream>
#include <vector>
using namespace std;

static int x = []() {
    ios::sync_with_stdio(false);
    return 0;
}();

const int size = 6;
const int N = 100010;
const int MS = 500011;

vector<int*> vec[MS];

bool equal(const int * l,const int * r) {
    int rst = 0;
    for (; rst < size; ++rst) {
        if (l[0] == r[rst]) {
            bool eq = true;
            for (int dx = 0; dx < size; ++dx) {
                if (l[dx] != r[(rst + dx) % size]) {
                    eq = false;
                    break;
                }
            }
            if (eq) return eq;
            eq = true;
            for (int dx = 0; dx < size; ++dx) {
                if (l[dx] != r[(rst - dx + size) % size]) {
                    eq = false;
                    break;
                }
            }
            if (eq) return eq;
        }
    }
    return false;
}

int main() {
    int n = 0, arr[size];
    long long sum, product;
    cin >> n;
    while (n--){
        sum = 0;
        product = 1;
        for(int & i : arr){
            cin>>i;
            sum = (sum + i) % MS;
            product = (product * i) % MS;
        }
        vector<int*>& vc = vec[(sum+product)%MS];
        if(!vc.empty()){
            for(const auto & i : vc){
                if(equal(arr, i)){
                    cout<<"Twin snowflakes found.";
                    return 0;
                }
            }
        }
        int * ta = new int[size];
        for(int i = 0 ; i < size; ++i) ta[i] = arr[i];
        vc.push_back(ta);
    }

    cout<<"No two snowflakes are alike.";
    return 0;
}